--- adb/commandline.h.orig	2016-09-28 18:07:09 UTC
+++ adb/commandline.h
@@ -17,6 +17,8 @@
 #ifndef COMMANDLINE_H
 #define COMMANDLINE_H
 
+#include <stdio.h> // fwrite
+
 #include "adb.h"
 
 // Callback used to handle the standard streams (stdout and stderr) sent by the
