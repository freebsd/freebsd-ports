--- StepmaniaCore.cmake.orig	2015-10-30 15:55:52.000000000 +0900
+++ StepmaniaCore.cmake	2015-11-09 01:49:26.062972000 +0900
@@ -308,7 +308,7 @@
     MAC_FRAME_OPENGL
     MAC_FRAME_QUICKTIME
   )
-elseif(LINUX)
+else()
   if(WITH_GTK2)
     find_package("GTK2" 2.0)
     if (${GTK2_FOUND})
@@ -350,26 +350,32 @@
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
