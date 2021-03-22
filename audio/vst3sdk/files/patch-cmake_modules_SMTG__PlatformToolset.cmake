--- cmake/modules/SMTG_PlatformToolset.cmake.orig	2021-03-22 20:22:49 UTC
+++ cmake/modules/SMTG_PlatformToolset.cmake
@@ -54,7 +54,7 @@ macro(smtg_setup_platform_toolset)
                     set(CMAKE_ANDROID_STL_TYPE c++_static)
                     link_libraries(dl)
                  else()
-                    link_libraries(stdc++fs pthread dl)
+                    link_libraries(pthread dl)
                 endif()
             endif()
         endif()
