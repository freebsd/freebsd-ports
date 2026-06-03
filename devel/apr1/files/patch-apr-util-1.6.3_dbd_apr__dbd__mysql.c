See https://bz.apache.org/bugzilla/show_bug.cgi?id=59332

Also reported in PR230538 devel/apr1 fails with mysql80-client

--- apr-util-1.6.3/dbd/apr_dbd_mysql.c.orig	2023-01-27 13:32:52 UTC
+++ apr-util-1.6.3/dbd/apr_dbd_mysql.c
@@ -44,6 +44,11 @@
 #include <errmsg.h>
 #endif
 
+#if !defined(HAVE_TYPE_MY_BOOL) && !defined(LIBMARIADB)
+#include <stdbool.h>
+typedef bool my_bool;
+#endif
+
 #include "apr_strings.h"
 #include "apr_lib.h"
 #include "apr_buckets.h"
