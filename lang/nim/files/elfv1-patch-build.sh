--- build.sh.orig	2019-10-24 12:53:39 UTC
+++ build.sh
@@ -84,7 +84,11 @@
     ;;
   *freebsd* )
     myos="freebsd"
-    CC="clang"
+    if [ "$ucpu" = "powerpc" ] ; then
+      CC="gcc"
+	else
+      CC="clang"
+    fi
     LINK_FLAGS="$LINK_FLAGS -lm"
     ;;
   *openbsd* )
