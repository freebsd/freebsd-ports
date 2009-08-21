--- ./svn.c.orig	2009-08-21 08:38:26.000000000 -0400
+++ ./svn.c	2009-08-21 08:38:33.000000000 -0400
@@ -34,6 +34,7 @@
 
 #include "apr_version.h"
 #include "svn_pools.h"
+#include "svn_props.h"
 #include "svn_sorts.h"
 #include "svn_config.h"
 #include "svn_auth.h"
