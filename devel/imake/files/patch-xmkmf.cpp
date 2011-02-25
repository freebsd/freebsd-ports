--- work/imake-1.0.2/xmkmf.cpp	2004-04-23 18:42:00.000000000 +0000
+++ xmkmf.cpp	2009-12-14 20:51:01.695597560 +0000
@@ -53,6 +53,10 @@
     args="-I$topdir/config/cf -DTOPDIR=$topdir -DCURDIR=$curdir"
 fi
 
+if [ -n "$CPP" -a -z "$IMAKECPP" ];then
+    export IMAKECPP=$CPP
+fi
+
 echo imake $imake_defines $args
 case "$do_all" in
 yes)
@@ -68,3 +72,12 @@
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
