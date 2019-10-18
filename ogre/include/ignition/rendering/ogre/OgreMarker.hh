/*
 * Copyright (C) 2019 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef IGNITION_RENDERING_OGRE_OGREMARKER_HH_
#define IGNITION_RENDERING_OGRE_OGREMARKER_HH_

#include <memory>
#include "ignition/rendering/base/BaseMarker.hh"
#include "ignition/rendering/ogre/OgreGeometry.hh"
#include "ignition/rendering/ogre/OgreIncludes.hh"

namespace ignition
{
  namespace rendering
  {
    inline namespace IGNITION_RENDERING_VERSION_NAMESPACE {
    //
    // Forward declaration
    class OgreMarkerPrivate;

    /// \brief Ogre implementation of a grid geometry.
    class IGNITION_RENDERING_OGRE_VISIBLE OgreMarker
      : public BaseMarker<OgreGeometry>
    {
      /// \brief Constructor
      protected: OgreMarker();

      /// \brief Destructor
      public: virtual ~OgreMarker();

      // Documentation inherited.
      public: virtual void Init();

      // Documentation inherited.
      public: virtual void PreRender();

      // Documentation inherited.
      public: virtual Ogre::MovableObject *OgreObject() const;

      // Documentation inherited.
      public: virtual MaterialPtr Material() const override;

      // Documentation inherited.
      public: virtual void SetMaterial(
                           MaterialPtr _material, bool _unique) override;

      public: virtual void SetRenderOperation(const MarkerType _markerType) override;

      public: virtual MarkerType RenderOperation() const override;

      public: virtual void SetPoint(const unsigned int _index,
                           const ignition::math::Vector3d &_value) override;

      public: virtual void AddPoint(const double _x,
                           const double _y, const double _z,
                           const ignition::math::Color &_color) override;

      public: virtual void AddPoint(const ignition::math::Vector3d &_pt,
                           const ignition::math::Color &_color) override;

      public: virtual void ClearPoints() override;

      public: virtual void SetType(const MarkerType _markerType) override;

      public: virtual MarkerType Type() const override;

      /// \brief Create the grid geometry in ogre
      private: void Create();

      /// \brief Marker should only be created by scene.
      private: friend class OgreScene;

      /// \brief Private data class
      private: std::unique_ptr<OgreMarkerPrivate> dataPtr;
    };
    }
  }
}
#endif
