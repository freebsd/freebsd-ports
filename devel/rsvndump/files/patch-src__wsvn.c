--- ./src/wsvn.c.orig	2009-04-13 11:10:13.000000000 -0400
+++ ./src/wsvn.c	2009-04-13 11:10:33.000000000 -0400
@@ -33,6 +33,7 @@
 #include <svn_fs.h>
 #include <svn_path.h>
 #include <svn_pools.h>
+#include <svn_props.h>
 #include <svn_ra.h>
 #include <svn_sorts.h>
 #include <svn_wc.h>
