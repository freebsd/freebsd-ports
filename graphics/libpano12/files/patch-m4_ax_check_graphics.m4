--- m4/ax_check_graphics.m4.orig	Wed Jan 17 11:09:58 2007
+++ m4/ax_check_graphics.m4	Wed Jan 17 11:11:53 2007
@@ -44,7 +44,7 @@
   ZLIB_OLD_LDFLAGS=$LDFLAGS
   ZLIB_OLD_CPPFLAGS=$CPPFLAGS
   if test "x$ZLIB_HOME" != 'x' ; then
-    if test "x$HCPU" = 'xamd64' ; then
+    if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
       LDFLAGS="$LDFLAGS -L$ZLIB_HOME/lib64"
     else
       LDFLAGS="$LDFLAGS -L$ZLIB_HOME/lib"
@@ -69,7 +69,7 @@
         LIB_ZLIB="-lz"
         ZLIB_FLAGS="-DHasZLIB"
       else
-        if test "x$HCPU" = 'xamd64' ; then
+        if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
           LIB_ZLIB="-L$ZLIB_HOME/lib64 -lz"
         else
           LIB_ZLIB="-L$ZLIB_HOME/lib -lz"
@@ -133,7 +133,7 @@
   PNG_OLD_LDFLAGS=$LDFLAGS
   PNG_OLD_CPPFLAGS=$CPPFLAGS
   if test "x$PNG_HOME" != 'x' ; then
-    if test "x$HCPU" = 'xamd64' ; then
+    if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
       LDFLAGS="$LDFLAGS -L$PNG_HOME/lib64"
     else
       LDFLAGS="$LDFLAGS -L$PNG_HOME/lib"
@@ -158,7 +158,7 @@
         LIB_PNG="-lpng"
         PNG_FLAGS="-DHasPNG"
       else
-        if test "x$HCPU" = 'xamd64' ; then
+        if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
           LIB_PNG="-L$PNG_HOME/lib64 -lpng"
         else
           LIB_PNG="-L$PNG_HOME/lib -lpng"
@@ -224,7 +224,7 @@
   JPEG_OLD_LDFLAGS=$LDFLAGS
   JPEG_OLD_CPPFLAGS=$CPPFLAGS
   if test "x$JPEG_HOME" != 'x' ; then
-    if test "x$HCPU" = 'xamd64' ; then
+    if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
       LDFLAGS="$LDFLAGS -L$JPEG_HOME/lib64"
     else
       LDFLAGS="$LDFLAGS -L$JPEG_HOME/lib"
@@ -274,7 +274,7 @@
         LIB_JPEG="-ljpeg"
         JPEG_FLAGS="-DHasJPEG"
       else
-        if test "x$HCPU" = 'xamd64' ; then
+        if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
           LIB_JPEG="-L$JPEG_HOME/lib64 -ljpeg"
         else
           LIB_JPEG="-L$JPEG_HOME/lib -ljpeg"
@@ -339,7 +339,7 @@
   TIFF_OLD_LDFLAGS=$LDFLAGS
   TIFF_OLD_CPPFLAGS=$CPPFLAGS
   if test "x$TIFF_HOME" != 'x' ; then
-    if test "x$HCPU" = 'xamd64' ; then
+    if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
       LDFLAGS="$LDFLAGS -L$TIFF_HOME/lib64"
     else
       LDFLAGS="$LDFLAGS -L$TIFF_HOME/lib"
@@ -364,7 +364,7 @@
         LIB_TIFF="-ltiff"
         TIFF_FLAGS="-DHasTIFF"
       else
-        if test "x$HCPU" = 'xamd64' ; then
+        if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
           LIB_TIFF="-L$TIFF_HOME/lib64 -ltiff"
         else
           LIB_TIFF="-L$TIFF_HOME/lib -ltiff"
