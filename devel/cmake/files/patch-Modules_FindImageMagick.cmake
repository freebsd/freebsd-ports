--- Modules/FindImageMagick.cmake.orig	2015-01-18 20:59:07.643587544 +0100
+++ Modules/FindImageMagick.cmake	2015-01-18 21:00:52.175617819 +0100
@@ -207,17 +207,17 @@
     )
   if(component STREQUAL "Magick++")
     FIND_IMAGEMAGICK_API(Magick++ Magick++.h
-      Magick++ CORE_RL_Magick++_ Magick++-6.Q16 Magick++-Q16 Magick++-6.Q8 Magick++-Q8 Magick++-6.Q16HDRI Magick++-Q16HDRI Magick++-6.Q8HDRI Magick++-Q8HDRI
+      Magick++ CORE_RL_Magick++_ Magick++-6 Magick++-6.Q16 Magick++-Q16 Magick++-6.Q8 Magick++-Q8 Magick++-6.Q16HDRI Magick++-Q16HDRI Magick++-6.Q8HDRI Magick++-Q8HDRI
       )
     list(APPEND ImageMagick_REQUIRED_VARS ImageMagick_Magick++_LIBRARY)
   elseif(component STREQUAL "MagickWand")
     FIND_IMAGEMAGICK_API(MagickWand wand/MagickWand.h
-      Wand MagickWand CORE_RL_wand_ MagickWand-6.Q16 MagickWand-Q16 MagickWand-6.Q8 MagickWand-Q8 MagickWand-6.Q16HDRI MagickWand-Q16HDRI MagickWand-6.Q8HDRI MagickWand-Q8HDRI
+      Wand MagickWand CORE_RL_wand_ MagickWand-6 MagickWand-6.Q16 MagickWand-Q16 MagickWand-6.Q8 MagickWand-Q8 MagickWand-6.Q16HDRI MagickWand-Q16HDRI MagickWand-6.Q8HDRI MagickWand-Q8HDRI
       )
     list(APPEND ImageMagick_REQUIRED_VARS ImageMagick_MagickWand_LIBRARY)
   elseif(component STREQUAL "MagickCore")
     FIND_IMAGEMAGICK_API(MagickCore magick/MagickCore.h
-      Magick MagickCore CORE_RL_magick_ MagickCore-6.Q16 MagickCore-Q16 MagickCore-6.Q8 MagickCore-Q8 MagickCore-6.Q16HDRI MagickCore-Q16HDRI MagickCore-6.Q8HDRI MagickCore-Q8HDRI
+      Magick MagickCore CORE_RL_magick_ MagickCore-6 MagickCore-6.Q16 MagickCore-Q16 MagickCore-6.Q8 MagickCore-Q8 MagickCore-6.Q16HDRI MagickCore-Q16HDRI MagickCore-6.Q8HDRI MagickCore-Q8HDRI
       )
     list(APPEND ImageMagick_REQUIRED_VARS ImageMagick_MagickCore_LIBRARY)
   else()
