--- cmake/modules/SMTG_PlatformToolset.cmake.orig	2021-12-16 12:29:25 UTC
+++ cmake/modules/SMTG_PlatformToolset.cmake
@@ -60,7 +60,7 @@ macro(smtg_setup_platform_toolset)
                     set(CMAKE_ANDROID_STL_TYPE c++_static)
                     link_libraries(dl)
                  else()
-                    link_libraries(stdc++fs pthread dl)
+                    link_libraries(pthread dl)
                 endif(ANDROID)
             endif(SMTG_MAC)
         endif(XCODE)
