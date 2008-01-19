--- m4/ax_check_panotools.m4.orig	Wed Dec 20 21:41:29 2006
+++ m4/ax_check_panotools.m4	Wed May  2 21:54:25 2007
@@ -57,7 +57,7 @@
     passed=0;
     PANO_OLD_LDFLAGS=$LDFLAGS
     PANO_OLD_CPPFLAGS=$CPPFLAGS
-    if test "x$HCPU" = 'xamd64' ; then
+    if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
       LDFLAGS="$LDFLAGS -L$PANO_HOME/lib64"
     else
       LDFLAGS="$LDFLAGS -L$PANO_HOME/lib"
@@ -95,7 +95,7 @@
             PANO_FLAGS="-DHasPANO12"
           fi
         else
-          if test "x$HCPU" = 'xamd64' ; then
+          if test "x$HCPU" = 'xamd64' -a "x$HSYS" != 'xfreebsd' ; then
             if test "$have_pano13" = 'yes' ; then
               LIB_PANO="-L$PANO_HOME/lib64 -lpano13"
             else
