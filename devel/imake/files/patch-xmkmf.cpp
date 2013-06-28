--- xmkmf.cpp.orig	2012-03-08 06:47:32.000000000 +0100
+++ xmkmf.cpp	2013-06-28 11:55:04.174394058 +0200
@@ -8,7 +8,7 @@
 topdir=
 curdir=.
 do_all=
-imake_defines=
+imake_defines="${IMAKECPPFLAGS}"
 
 while [ $# -gt 0 ]
 do
@@ -64,3 +64,12 @@
     imake $imake_defines $args
     ;;
 esac
+
+if [ -f "Makefile" ];then
+    if [ -n "$CC" ];then
+        sed -i "" -e "s| CC = cc| CC = $CC|" Makefile
+    fi
+    if [ -n "$CXX" ];then
+        sed -i "" -e "s| CXX = c++| CXX = $CXX|" Makefile
+    fi
+fi
