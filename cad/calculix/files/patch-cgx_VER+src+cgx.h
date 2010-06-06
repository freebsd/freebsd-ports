--- cgx_2.1/src/cgx.h.orig	2009-08-13 15:58:59.000000000 +0900
+++ cgx_2.1/src/cgx.h	2009-09-03 15:07:10.000000000 +0900
@@ -86,8 +86,8 @@
                              "/yaprod/cae/application/CalculiX/doc/ccx_2.0/ccx.html"}
   #endif
 #else
-  #define     HELPFILE        {"/usr/local/CalculiX/cgx_2.1/doc/cgx/cgx.html",\
-    "/usr/local/CalculiX/ccx_2.1/doc/ccx/ccx.html"}
+   #define     HELPFILE        {"%%DOCSDIR%%/cgx/cgx.html",\
+     "%%DOCSDIR%%/ccx/ccx.html"}
 #endif
 
 /* html browser, change if necessary */
