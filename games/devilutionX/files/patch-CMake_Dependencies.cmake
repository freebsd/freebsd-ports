--- CMake/Dependencies.cmake.orig	2022-07-25 04:41:06 UTC
+++ CMake/Dependencies.cmake
@@ -31,7 +31,9 @@ else()
   if(DEVILUTIONX_SYSTEM_SDL2)
     find_package(SDL2 REQUIRED)
     if(TARGET SDL2::SDL2)
-      set(SDL2_MAIN SDL2::SDL2main)
+      if(TARGET SDL2::SDL2main)
+        set(SDL2_MAIN SDL2::SDL2main)
+      endif()
     elseif(TARGET SDL2::SDL2-static)
       # On some distros, such as vitasdk, only the SDL2::SDL2-static target is available.
       # Alias to SDL2::SDL2 because some finder scripts may refer to SDL2::SDL2.
