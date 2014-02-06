--- debug.cpp.orig	2013-11-26 02:52:18.384654297 +0400
+++ debug.cpp	2013-11-26 02:52:27.078654024 +0400
@@ -8,7 +8,6 @@
 
 
 #if !(defined _WIN32 || defined WINDOWS || defined __CYGWIN__)
-#include <execinfo.h>
 #include <stdlib.h>
 #endif
 
