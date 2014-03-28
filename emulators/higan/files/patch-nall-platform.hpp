--- ./nall/platform.hpp.orig	2014-03-16 21:33:25.000000000 -0400
+++ ./nall/platform.hpp	2014-03-16 21:45:07.000000000 -0400
@@ -41,7 +41,7 @@
   #undef interface
   #define dllexport __declspec(dllexport)
 #else
-  #include <endian.h>
+  #include <sys/endian.h>
   #include <unistd.h>
   #include <pwd.h>
   #define dllexport
