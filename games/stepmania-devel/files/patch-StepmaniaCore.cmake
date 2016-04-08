--- StepmaniaCore.cmake.orig	2016-03-30 16:08:58 UTC
+++ StepmaniaCore.cmake
@@ -308,7 +308,7 @@ elseif(MACOSX)
     MAC_FRAME_OPENGL
     MAC_FRAME_QUICKTIME
   )
-elseif(LINUX)
+else()
   if(WITH_GTK2)
     find_package("GTK2" 2.0)
     if (${GTK2_FOUND})
@@ -350,26 +350,32 @@ elseif(LINUX)
     set(HAX_XRANDR FALSE)
   endif()
 
+  if(WITH_PULSE)
   find_package(PulseAudio)
   if (PULSEAUDIO_FOUND)
     set(HAS_PULSE TRUE)
   else()
     set(HAS_PULSE FALSE)
   endif()
+  endif()
 
+  if(WITH_ALSA)
   find_package(ALSA)
   if (ALSA_FOUND)
     set(HAS_ALSA TRUE)
   else()
     set(HAS_ALSA FALSE)
   endif()
+  endif()
 
+  if(WITH_JACK)
   find_package(JACK)
   if (JACK_FOUND)
     set(HAS_JACK TRUE)
   else()
     set(HAS_JACK FALSE)
   endif()
+  endif()
 
   find_package(OSS)
   if (OSS_FOUND)
