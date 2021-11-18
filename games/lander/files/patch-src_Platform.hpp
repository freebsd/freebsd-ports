--- src/Platform.hpp.orig	2014-02-02 18:23:11 UTC
+++ src/Platform.hpp
@@ -90,9 +90,6 @@
 #include <sys/stat.h>
 #include <unistd.h>
 
-// Probably using GCC
-#include <tr1/memory>
-
 #endif /* #ifdef WIN32 */
 
 // Mac OS X specifics */
