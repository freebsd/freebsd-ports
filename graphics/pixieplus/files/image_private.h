/*
  Copyright 1999-2004 ImageMagick Studio LLC, a non-profit organization
  dedicated to making software imaging solutions freely available.
  
  You may not use this file except in compliance with the License.
  obtain a copy of the License at
  
    http://www.imagemagick.org/www/Copyright.html
  
  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  ImageMagick private image methods.
*/
#ifndef _MAGICK_IMAGE_PRIVATE_H
#define _MAGICK_IMAGE_PRIVATE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

extern MagickExport const char
  *BackgroundColor,
  *BorderColor,
  *DefaultTileFrame,
  *DefaultTileGeometry,
  *DefaultTileLabel,
  *ForegroundColor,
  *MatteColor,
  *LoadImageTag,
  *LoadImagesTag,
  *PSDensityGeometry,
  *PSPageGeometry,
  *SaveImageTag,
  *SaveImagesTag;

extern MagickExport const unsigned long
  UndefinedCompressionQuality;

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
