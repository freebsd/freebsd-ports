--- nall/platform.hpp.orig	2014-01-20 06:37:12 UTC
+++ nall/platform.hpp
@@ -41,7 +41,7 @@ namespace Math {
   #undef interface
   #define dllexport __declspec(dllexport)
 #else
-  #include <endian.h>
+  #include <sys/endian.h>
   #include <unistd.h>
   #include <pwd.h>
   #define dllexport
