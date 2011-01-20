--- main.cpp.orig	1999-07-13 10:32:55.000000000 -0700
+++ main.cpp	2011-01-18 14:22:52.000000000 -0800
@@ -24,6 +24,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <qstring.h>
 #include "config.h"
@@ -37,6 +38,8 @@
 {
   EarthApplication myApp(argc, argv);
 
+  srandomdev();
+
 #ifdef WITH_QIMAGEIO
   qInitImageIO();
 #endif
