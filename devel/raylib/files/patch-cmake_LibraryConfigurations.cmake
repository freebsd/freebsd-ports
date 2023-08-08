--- cmake/LibraryConfigurations.cmake.orig	2022-09-30 14:46:52 UTC
+++ cmake/LibraryConfigurations.cmake
@@ -27,7 +27,7 @@ if (${PLATFORM} MATCHES "Desktop")
             find_library(OSS_LIBRARY ossaudio)
         endif ()
 
-        set(LIBS_PRIVATE m atomic pthread ${OPENGL_LIBRARIES} ${OSS_LIBRARY})
+        set(LIBS_PRIVATE m pthread ${OPENGL_LIBRARIES} ${OSS_LIBRARY})
 
         if (USE_AUDIO)
             set(LIBS_PRIVATE ${LIBS_PRIVATE} dl)
