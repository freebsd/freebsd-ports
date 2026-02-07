--- xpdf-qt/XpdfWidgetPrint.cc.orig	2017-08-08 16:22:50.000000000 -0700
+++ xpdf-qt/XpdfWidgetPrint.cc	2017-09-17 21:42:14.242967000 -0700
@@ -21,7 +21,7 @@
 #elif defined(__APPLE__)
 #  include <CoreFoundation/CoreFoundation.h>
 #  include <ApplicationServices/ApplicationServices.h>
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 #  include "PSOutputDev.h"
 #  include <cups/cups.h>
 #endif
@@ -315,7 +315,7 @@
 // Linux
 //------------------------------------------------------------------------
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
 static void fileOut(void *stream, const char *data, int len) {
   fwrite(data, 1, len, (FILE *)stream);
