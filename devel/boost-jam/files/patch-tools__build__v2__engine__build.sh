--- ./tools/build/v2/engine/build.sh.orig	2012-04-26 05:35:55.000000000 +0200
+++ ./tools/build/v2/engine/build.sh	2013-05-01 10:24:50.730247378 +0200
@@ -128,8 +128,9 @@
     BOOST_JAM_CC="gcc -DNT"
     ;;
 
-    gcc)
-    BOOST_JAM_CC=gcc
+    gcc*)
+    BOOST_JAM_CC=$BOOST_JAM_TOOLSET
+    BOOST_JAM_TOOLSET=gcc
     ;;
 
     darwin)
