--- freedoko.cpp.orig	2011-12-18 06:05:12.000000000 -0200
+++ freedoko.cpp	2013-11-26 13:40:09.390150518 -0200
@@ -43,6 +43,7 @@
 #else
 // for 'mkdir'
 #include <sys/stat.h>
+#include <unistd.h>
 #endif
 
 #include "class/getopt/getopt.h"
