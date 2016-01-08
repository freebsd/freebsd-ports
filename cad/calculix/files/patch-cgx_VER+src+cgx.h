--- cgx_2.9/src/cgx.h.orig	2015-11-14 14:00:48 UTC
+++ cgx_2.9/src/cgx.h
@@ -83,8 +83,8 @@ rendering is done in the index-mode.
     "/usr/local/CalculiX/ccx_2.9/doc/ccx/ccx.html",\
     "/usr/local/CalculiX/cgx_2.9/doc/aflib/aflib.pdf"}
 #else
-  #define     HELPFILE        {"/usr/local/CalculiX/cgx_2.9/doc/cgx/cgx.html",\
-    "/usr/local/CalculiX/ccx_2.9/doc/ccx/ccx.html"}
+   #define     HELPFILE        {"/usr/local/share/doc/CalculiX/cgx/cgx.html",\
+     "/usr/local/share/doc/CalculiX/ccx/ccx.html"}
 #endif
 
 /* html browser, change if necessary */
