--- postgres.c.orig	Sun Mar 18 20:58:14 2001
+++ postgres.c	Mon Apr 23 05:29:22 2001
@@ -19,6 +19,7 @@
 #include <libpq/libpq-fs.h>              /* large-object interface */
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
 
 static VALUE rb_cPGconn;
 static VALUE rb_cPGresult;
