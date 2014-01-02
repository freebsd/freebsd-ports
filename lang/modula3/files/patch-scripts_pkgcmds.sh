--- scripts/pkgcmds.sh.orig	2010-04-15 20:02:46.000000000 +0000
+++ scripts/pkgcmds.sh
@@ -43,6 +43,8 @@ map_action() {
     ACTION="${BUILDLOCAL}"
   elif [ "$1" = "buildglobal" -o "$1" = "buildship" ] ; then
     ACTION="${BUILDGLOBAL} && ${SHIP}"
+  elif [ "$1" = "onlybuild" ] ; then
+    ACTION="${BUILDGLOBAL}"
   elif [ "$1" = "ship" ] ; then
     ACTION="${SHIP}"
   elif [ "$1" = "clean" -o "$1" = "cleanlocal" ] ; then
