--- ./Common/DefaultOptions.h.orig	Sun Oct 17 04:49:26 2004
+++ ./Common/DefaultOptions.h	Sun Oct 17 22:50:05 2004
@@ -65,7 +65,7 @@
 #elif defined(__APPLE__)
     "open -e %s" ,
 #else
-    "emacs %s &" ,
+    "$EDITOR %s &" ,
 #endif
     "System command to launch a text editor" },
   { F|S, "TmpFileName" , opt_general_tmp_filename , ".gmsh-tmp" ,
