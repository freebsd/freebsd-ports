--- src/general/init/init.sh.orig	Sun Mar 16 21:25:20 2003
+++ src/general/init/init.sh	Thu Oct  9 23:09:58 2003
@@ -165,12 +165,12 @@
 fi
 
 if [ ! "$GRASS_TCLSH" ] ; then
-    GRASS_TCLSH=tclsh
+    GRASS_TCLSH=tclsh8.3
     export GRASS_TCLSH
 fi
 
 if [ ! "$GRASS_WISH" ] ; then
-    GRASS_WISH=wish
+    GRASS_WISH=wish8.3
     export GRASS_WISH
 fi
 
