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

  ImageMagick private exception methods.
*/
#ifndef _MAGICK_EXCEPTION_PRIVATE_H
#define _MAGICK_EXCEPTION_PRIVATE_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

#include "magick/log.h"

#define ThrowBinaryException(severity,tag,context) \
{ \
  if (image != (Image *) NULL) \
    (void) ThrowMagickException(&image->exception,GetMagickModule(),severity, \
      tag,context); \
  return(MagickFalse); \
}
#define ThrowFileException(exception,severity,tag,context) \
  (void) ThrowMagickException(exception,GetMagickModule(),severity,tag, \
    context,strerror(errno));
#define ThrowImageException(severity,tag) \
{ \
  (void) ThrowMagickException(exception,GetMagickModule(),severity,tag, \
    image->filename); \
  return((Image *) NULL); \
}
#define ThrowMagickFatalException(severity,tag,context) \
{ \
  ExceptionInfo \
    exception; \
 \
  GetExceptionInfo(&exception); \
  (void) ThrowMagickException(&exception,GetMagickModule(),severity,tag, \
    context); \
  CatchException(&exception); \
  DestroyExceptionInfo(&exception); \
}
#define ThrowReaderException(severity,tag) \
{ \
  (void) ThrowMagickException(exception,GetMagickModule(),severity,tag, \
    image_info->filename); \
  if ((image) != (Image *) NULL) \
    { \
      CloseBlob(image); \
      DestroyImageList(image); \
    } \
  return((Image *) NULL); \
}
#define ThrowWriterException(severity,tag) \
{ \
  assert(image != (Image *) NULL); \
  (void) ThrowMagickException(&image->exception,GetMagickModule(),severity, \
    tag,image->filename); \
  if (image_info->adjoin != MagickFalse) \
    while (image->previous != (Image *) NULL) \
      image=image->previous; \
  CloseBlob(image); \
  return(MagickFalse); \
}
#define ThrowXWindowException(severity,tag,context) \
{ \
  ExceptionInfo \
    exception; \
 \
  GetExceptionInfo(&exception); \
  (void) ThrowMagickException(&exception,GetMagickModule(),severity,tag, \
    context); \
  CatchException(&exception); \
  DestroyExceptionInfo(&exception); \
}

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif

#endif
