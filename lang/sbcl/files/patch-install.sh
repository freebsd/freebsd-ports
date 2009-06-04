--- install.sh.orig	2009-06-04 18:51:44.000000000 +0400
+++ install.sh	2009-06-04 18:51:48.000000000 +0400
@@ -138,7 +138,7 @@
       && echo " html $BUILD_ROOT$DOC_DIR/html/`basename $html`/index.html"
 done
 
-for f in BUGS SUPPORT CREDITS COPYING NEWS
+for f in BUGS CREDITS COPYING NEWS
 do
   cp $f "$BUILD_ROOT$DOC_DIR"/
 done
