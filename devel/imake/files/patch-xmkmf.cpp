--- xmkmf.cpp.orig	2012-03-08 06:47:32.000000000 +0100
+++ xmkmf.cpp	2013-03-17 22:53:14.000000000 +0100
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
