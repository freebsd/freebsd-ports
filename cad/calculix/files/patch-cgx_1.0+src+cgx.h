--- cgx_1.0/src/cgx.h.orig	Mon Apr  7 14:28:01 2003
+++ cgx_1.0/src/cgx.h	Thu May  8 13:25:32 2003
@@ -46,14 +46,14 @@
 #define     MILLISECONDS_PER_PERIOD 1200 
 
 /* default location of the help files, please insert the actual one */
-#define     HELPFILE        {"/usr/local/CalculiX/cgx_1.0/doc/cgx/cgx.html",\
-   "/usr/local/CalculiX/ccx_1.0/doc/ccx/ccx.html"}
+#define     HELPFILE    {"%%DOCSDIR%%/cgx/cgx.html",\
+   "%%DOCSDIR%%/ccx/ccx.html"}
 
 /* html browser, change if necessary */
-#define     BROWSER         {"netscape"}
+#define     BROWSER         {"mozilla"}
 
 /* postscript viewer, change if necessary */
-#define     PSVIEWER         {"ghostview"}
+#define     PSVIEWER         {"gv"}
 
 /* more parameters, better do not change them! */
 #define     MINVALUE    -1.e9
