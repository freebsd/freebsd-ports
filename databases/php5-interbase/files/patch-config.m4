--- config.m4.orig	2010-03-25 11:04:06.000000000 +0100
+++ config.m4	2010-03-25 11:05:20.000000000 +0100
@@ -15,10 +15,6 @@
     IBASE_LIBDIR=$PHP_INTERBASE/$PHP_LIBDIR
   fi
 
-  PHP_CHECK_LIBRARY(fbclient, isc_detach_database,
-  [
-    IBASE_LIBNAME=fbclient
-  ], [
     PHP_CHECK_LIBRARY(gds, isc_detach_database,
     [
       IBASE_LIBNAME=gds
@@ -34,9 +30,6 @@
     ], [
       -L$IBASE_LIBDIR
     ])
-  ], [
-    -L$IBASE_LIBDIR
-  ])
   
   PHP_ADD_LIBRARY_WITH_PATH($IBASE_LIBNAME, $IBASE_LIBDIR, INTERBASE_SHARED_LIBADD)
   PHP_ADD_INCLUDE($IBASE_INCDIR)
