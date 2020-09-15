--- build.sh.orig	2019-10-24 12:53:39 UTC
+++ build.sh
@@ -84,7 +84,11 @@
     ;;
   *freebsd* )
     myos="freebsd"
-    CC="clang"
+    if [ "$ucpu" = "powerpc" ] ; then
+      CC="gcc%%GCC_DEFAULT%%"
+	else
+      CC="clang"
+    fi
     LINK_FLAGS="$LINK_FLAGS -lm"
     ;;
   *openbsd* )
--- config/nim.cfg.orig	2020-09-15 13:59:31 UTC
+++ config/nim.cfg
@@ -9,6 +9,7 @@
 #  gcc.path %= "$CC_PATH"
 
 cc = gcc
+gcc.exe = "gcc%%GCC_DEFAULT%%"
 
 # additional options always passed to the compiler:
 --parallel_build: "0" # 0 to auto-detect number of processors
