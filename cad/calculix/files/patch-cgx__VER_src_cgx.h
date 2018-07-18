--- cgx_2.14/src/cgx.h.orig	2017-04-28 10:12:50 UTC
+++ cgx_2.14/src/cgx.h
@@ -89,8 +89,8 @@ rendering is done in the index-mode.
     "/usr/local/CalculiX/ccx_2.14/doc/ccx/ccx.html",\
     "/usr/local/CalculiX/cgx_2.14/doc/aflib/aflib.pdf"}
 #else
-  #define     HELPFILE        {"/usr/local/CalculiX/cgx_2.14/doc/cgx/cgx.html",\
-    "/usr/local/CalculiX/ccx_2.14/doc/ccx/ccx.html"}
+  #define     HELPFILE        {"/usr/local/share/doc/CalculiX/cgx/cgx.html",\
+    "/usr/local/share/doc/CalculiX/ccx/ccx.html"}
 #endif
 
 /* html browser, change if necessary */
