--- main.cpp.orig	1999-07-13 17:32:55 UTC
+++ main.cpp
@@ -24,6 +24,7 @@
  */
 
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include <qstring.h>
 #include "config.h"
@@ -37,6 +38,8 @@ int main(int argc, char **argv)
 {
   EarthApplication myApp(argc, argv);
 
+  srandomdev();
+
 #ifdef WITH_QIMAGEIO
   qInitImageIO();
 #endif
