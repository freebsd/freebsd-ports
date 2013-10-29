--- include/sysutil.h.orig	2013-09-24 15:26:10.604215091 +0930
+++ include/sysutil.h	2013-09-24 15:26:16.727214989 +0930
@@ -41,6 +41,7 @@
 #define OPENIMAGEIO_SYSUTIL_H
 
 #include <string>
+#include <time.h>
 
 #ifdef __MINGW32__
 #include <malloc.h> // for alloca
