--- vst3sdk/cmake/modules/PlatformToolset.cmake.orig	2020-04-15 18:18:33 UTC
+++ vst3sdk/cmake/modules/PlatformToolset.cmake
@@ -32,7 +32,7 @@ macro(setupPlatformToolset)
         else()
             set(CMAKE_POSITION_INDEPENDENT_CODE TRUE)
             set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wno-multichar")
-            link_libraries(stdc++fs pthread dl)
+            link_libraries(pthread dl)
         endif()
     #------------
     elseif(SMTG_WIN)
