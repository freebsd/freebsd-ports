--- cgx_2.10/src/cgx.h.orig	2016-03-05 16:23:57 UTC
+++ cgx_2.10/src/cgx.h
@@ -83,8 +83,8 @@ rendering is done in the index-mode.
     "/usr/local/CalculiX/ccx_2.10/doc/ccx/ccx.html",\
     "/usr/local/CalculiX/cgx_2.10/doc/aflib/aflib.pdf"}
 #else
-  #define     HELPFILE        {"/usr/local/CalculiX/cgx_2.10/doc/cgx/cgx.html",\
-    "/usr/local/CalculiX/ccx_2.10/doc/ccx/ccx.html"}
+   #define     HELPFILE        {"/usr/local/share/doc/CalculiX/cgx/cgx.html",\
+     "/usr/local/share/doc/CalculiX/ccx/ccx.html"}
 #endif
 
 /* html browser, change if necessary */
