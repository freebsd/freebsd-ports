--- m4/ax_check_panotools.m4.orig	Wed Jan 17 15:30:39 2007
+++ m4/ax_check_panotools.m4	Wed Jan 17 15:31:10 2007
@@ -44,7 +44,7 @@
     passed=0;
     PANO_OLD_LDFLAGS=$LDFLAGS
     PANO_OLD_CPPFLAGS=$CPPFLAGS
-    if test "x$HCPU" = 'xamd64' ; then
+    if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
       LDFLAGS="$LDFLAGS -L$PANO_HOME/lib64"
     else
       LDFLAGS="$LDFLAGS -L$PANO_HOME/lib"
@@ -76,7 +76,7 @@
           LIB_PANO="-lpano12"
           PANO_FLAGS="-DHasPANO"
         else
-          if test "x$HCPU" = 'xamd64' ; then
+          if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
             LIB_PANO="-L$PANO_HOME/lib64 -lpano12"
           else
             LIB_PANO="-L$PANO_HOME/lib -lpano12"
