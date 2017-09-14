Insert an additional search item when finding ImageMagick, originally
from kwm (see below), adjusted for new organization of search paths.

Author: kwm <kwm@FreeBSD.org>
Date:   Sun Jan 18 21:12:42 2015 +0000

    Update ImageMagick to 6.9.0.4.
    
    - Normalize the ImageMagick library name so it stays the same regardless of
      what the 16-bit and HDRI option are set to [1]. Teach cmake to look for
      the new name. Bump ports that link to the libraries due to this.

--- Modules/FindImageMagick.cmake.orig	2017-07-27 18:33:53.634381000 +0200
+++ Modules/FindImageMagick.cmake	2017-07-27 18:36:31.110708000 +0200
@@ -196,6 +196,7 @@
   if(component STREQUAL "Magick++")
     FIND_IMAGEMAGICK_API(Magick++ Magick++.h
       Magick++ CORE_RL_Magick++_
+      Magick++-6
       Magick++-Q8 Magick++-Q16 Magick++-Q16HDRI Magick++-Q8HDRI
       Magick++-6.Q16 Magick++-6.Q8 Magick++-6.Q16HDRI Magick++-6.Q8HDRI
       Magick++-7.Q16 Magick++-7.Q8 Magick++-7.Q16HDRI Magick++-7.Q8HDRI
@@ -204,6 +205,7 @@
   elseif(component STREQUAL "MagickWand")
     FIND_IMAGEMAGICK_API(MagickWand "wand/MagickWand.h;MagickWand/MagickWand.h"
       Wand MagickWand CORE_RL_wand_
+      MagickWand-6
       MagickWand-Q16 MagickWand-Q8 MagickWand-Q16HDRI MagickWand-Q8HDRI
       MagickWand-6.Q16 MagickWand-6.Q8 MagickWand-6.Q16HDRI MagickWand-6.Q8HDRI
       MagickWand-7.Q16 MagickWand-7.Q8 MagickWand-7.Q16HDRI MagickWand-7.Q8HDRI
@@ -212,6 +214,7 @@
   elseif(component STREQUAL "MagickCore")
     FIND_IMAGEMAGICK_API(MagickCore "magick/MagickCore.h;MagickCore/MagickCore.h"
       Magick MagickCore CORE_RL_magick_
+      MagickCore-6
       MagickCore-Q16 MagickCore-Q8 MagickCore-Q16HDRI MagickCore-Q8HDRI
       MagickCore-6.Q16 MagickCore-6.Q8 MagickCore-6.Q16HDRI MagickCore-6.Q8HDRI
       MagickCore-7.Q16 MagickCore-7.Q8 MagickCore-7.Q16HDRI MagickCore-7.Q8HDRI
