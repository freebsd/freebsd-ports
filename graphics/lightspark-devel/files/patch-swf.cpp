--- swf.cpp.orig	2011-03-07 07:10:16.000000000 +0300
+++ swf.cpp	2011-03-09 01:20:14.000000000 +0300
@@ -39,6 +39,8 @@
 
 #include "compat.h"
 
+extern char **environ;
+
 #ifdef ENABLE_LIBAVCODEC
 extern "C" {
 #include <libavcodec/avcodec.h>
