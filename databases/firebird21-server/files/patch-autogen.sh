--- autogen.sh.orig	2010-09-08 15:44:05.000000000 +0700
+++ autogen.sh	2010-10-18 13:37:36.000000000 +0700
@@ -63,7 +63,7 @@
 fi
 
 echo "Running autoreconf ..."
-$AUTORECONF --install --force --verbose || exit 1
+$AUTORECONF --install --force --verbose -I ./m4 || exit 1
 
 # Hack to bypass bug in autoreconf - --install switch not passed to libtoolize,
 # therefore missing config.sub and confg.guess files
