--- cmake/modules/SMTG_PlatformToolset.cmake.orig	2024-07-26 07:55:28 UTC
+++ cmake/modules/SMTG_PlatformToolset.cmake
@@ -62,7 +62,7 @@ macro(smtg_setup_platform_toolset)
                     set(CMAKE_ANDROID_STL_TYPE c++_static)
                     link_libraries(dl)
                  else()
-                    link_libraries(stdc++fs pthread dl)
+                    link_libraries(pthread dl)
                 endif(ANDROID)
             endif(SMTG_MAC)
         endif(XCODE)
