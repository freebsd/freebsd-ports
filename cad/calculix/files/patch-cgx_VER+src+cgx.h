--- cgx_1.1/src/cgx.h.orig	Tue Aug  5 10:08:37 2003
+++ cgx_1.1/src/cgx.h	Thu Aug  7 00:37:38 2003
@@ -59,8 +59,8 @@
 #define     MILLISECONDS_PER_PERIOD 1200 
 
 /* default location of the help files, please insert the actual one */
-#define     HELPFILE        {"/usr/local/CalculiX/cgx_1.1/doc/cgx/cgx.html",\
-   "/usr/local/CalculiX/ccx_1.1/doc/ccx/ccx.html"}
+#define     HELPFILE        {"%%DOCSDIR%%/cgx/cgx.html",\
+   "%%DOCSDIR%%/ccx/ccx.html"}
 
 /* html browser, change if necessary */
 #define     BROWSER         {"netscape"}
