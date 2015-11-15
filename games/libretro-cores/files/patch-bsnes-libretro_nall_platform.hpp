--- bsnes-libretro/nall/platform.hpp.orig	2015-10-22 07:40:14 UTC
+++ bsnes-libretro/nall/platform.hpp
@@ -41,11 +41,7 @@ namespace Math {
   #undef interface
   #define dllexport __declspec(dllexport)
 #else
-  #ifdef __APPLE__
-    #include <machine/endian.h>
-  #else
-    #include <endian.h>
-  #endif
+  #include <machine/endian.h>
   #include <unistd.h>
   #include <pwd.h>
   #define dllexport
