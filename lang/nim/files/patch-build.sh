--- build.sh.orig	2021-11-07 03:12:45 UTC
+++ build.sh
@@ -191,8 +191,10 @@ case $ucpu in
     mycpu="powerpc64" ;;
   *power*|*ppc* )
     if [ "$myos" = "freebsd" ] ; then
-      COMP_FLAGS="$COMP_FLAGS -m64"
-      LINK_FLAGS="$LINK_FLAGS -m64"
+      if [ "$ucpu" != "powerpc" ] ; then
+        COMP_FLAGS="$COMP_FLAGS -m64"
+        LINK_FLAGS="$LINK_FLAGS -m64"
+      fi
       mycpu=`uname -p`
       case $mycpu in
         powerpc64le)
