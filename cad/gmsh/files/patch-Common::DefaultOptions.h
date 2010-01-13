--- Common/DefaultOptions.h.orig	2010-01-01 14:21:13.000000000 -0600
+++ Common/DefaultOptions.h	2010-01-01 14:22:28.000000000 -0600
@@ -70,7 +70,7 @@
 #elif defined(__APPLE__)
     "open -t %s" ,
 #else
-    "emacs '%s' &" ,
+    "$EDITOR '%s' &" ,
 #endif
     "System command to launch a text editor" },
   { F|S, "TmpFileName" , opt_general_tmp_filename , ".gmsh-tmp" ,
