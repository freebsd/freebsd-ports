--- cgx_1.2/src/cgx.h.orig	Sat Jul 17 17:17:41 2004
+++ cgx_1.2/src/cgx.h	Thu Dec 23 15:32:58 2004
@@ -59,8 +59,8 @@
 #define     MILLISECONDS_PER_PERIOD 1200 
 
 /* default location of the help files, please insert the actual one */
-#define     HELPFILE        {"/usr/local/CalculiX/cgx_1.2/doc/cgx/cgx.html",\
-    "/usr/local/CalculiX/ccx_1.2/doc/ccx/ccx.html"}
+#define     HELPFILE        {"%%DOCSDIR%%/cgx/cgx.html",\
+    "%%DOCSDIR%%/ccx/ccx.html"}
 
 /* html browser, change if necessary */
 /* #define     BROWSER         {"netscape"} */
