--- cgx_1.3/src/cgx.h.orig	Fri Feb 25 20:00:16 2005
+++ cgx_1.3/src/cgx.h	Sat Feb 26 20:45:51 2005
@@ -63,8 +63,8 @@
 #define     MILLISECONDS_PER_PERIOD 1200 
 
 /* default location of the help files, please insert the actual one */
-#define     HELPFILE        {"/usr/local/CalculiX/cgx_1.3/doc/cgx/cgx.html",\
-    "/usr/local/CalculiX/ccx_1.3/doc/ccx/ccx.html"} 
+#define     HELPFILE        {"%%DOCSDIR%%/cgx/cgx.html",\
+    "%%DOCSDIR%%/ccx/ccx.html"} 
 
 /* html browser, change if necessary */
 /* #define     BROWSER         {"netscape"} */
