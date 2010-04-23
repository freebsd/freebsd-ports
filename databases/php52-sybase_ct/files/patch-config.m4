--- config.m4.orig	2009-03-26 09:53:49.000000000 +0100
+++ config.m4	2009-03-26 09:55:35.000000000 +0100
@@ -31,7 +31,7 @@
   fi
   
   PHP_ADD_LIBPATH($SYBASE_CT_LIBDIR, SYBASE_CT_SHARED_LIBADD)
-  if test -f $SYBASE_CT_INCDIR/tds.h; then
+  if test -f $SYBASE_CT_INCDIR/tds_sysdep_public.h; then
     PHP_ADD_LIBRARY(ct,, SYBASE_CT_SHARED_LIBADD)
     SYBASE_CT_LIBS="-L$SYBASE_CT_LIBDIR -lct"
   else
