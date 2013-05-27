--- config.m4.orig	2013-05-27 14:05:52.000000000 +0200
+++ config.m4	2013-05-27 14:06:16.000000000 +0200
@@ -15,7 +15,7 @@
   if test "$PHP_FRIBIDI" = "yes"; then
     FRIBIDI_PKG_CONFIG_CMD="$FRIBIDI_PKG_CONFIG fribidi"
   else
-    FRIBIDI_PKG_CONFIG_CMD="$FRIBIDI_PKG_CONFIG $PHP_FRIBIDI/lib/pkgconfig/fribidi.pc"
+    FRIBIDI_PKG_CONFIG_CMD="$FRIBIDI_PKG_CONFIG $PHP_FRIBIDI/libdata/pkgconfig/fribidi.pc"
   fi
 
   dnl check for fribidi version
