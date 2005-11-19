--- cgx_1.4/src/cgx.h.orig	Mon Oct 10 15:46:23 2005
+++ cgx_1.4/src/cgx.h	Mon Oct 10 16:06:53 2005
@@ -77,8 +77,8 @@
 #define     MILLISECONDS_PER_PERIOD 1200 
 
 /* default location of the help files, please insert the actual one */
-#define     HELPFILE        {"/usr/local/CalculiX/cgx_1.4/doc/cgx/cgx.html",\
-    "/usr/local/CalculiX/ccx_1.4/doc/ccx/ccx.html"}
+#define     HELPFILE        {"%%DOCSDIR%%/cgx/cgx.html",\
+     "%%DOCSDIR%%/ccx/ccx.html"} 
 
 
 /* html browser, change if necessary */
