--- cgx_1.5/src/cgx.h.orig	Sun Feb 19 22:07:26 2006
+++ cgx_1.5/src/cgx.h	Sun Feb 19 22:09:50 2006
@@ -86,8 +86,8 @@
                              "/yaprod/cae/application/CalculiX/doc/ccx/ccx.html"}
   #endif
 #else
-  #define     HELPFILE        {"/usr/local/CalculiX/cgx_1.5/doc/cgx/cgx.html",\
-    "/usr/local/CalculiX/ccx_1.5/doc/ccx/ccx.html"}
+  #define     HELPFILE        {"%%DOCSDIR%%/cgx/cgx.html",\
+    "%%DOCSDIR%%/ccx/ccx.html"}
 #endif
 
 /* html browser, change if necessary */
