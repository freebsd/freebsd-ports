--- src/general/init/init.sh.orig	Tue Feb 12 11:32:40 2002
+++ src/general/init/init.sh	Tue Feb 12 11:32:52 2002
@@ -76,12 +76,12 @@
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
 
