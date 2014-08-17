--- include/tdsodbc.h.orig	2006-02-24 21:14:21.000000000 +0000
+++ include/tdsodbc.h
@@ -31,8 +31,8 @@
 #include <sql.h>
 #include <sqlext.h>
 #else /* IODBC */
-#include <isql.h>
-#include <isqlext.h>
+#include <libiodbc/isql.h>
+#include <libiodbc/isqlext.h>
 #ifdef HAVE_IODBCINST_H
 #include <iodbcinst.h>
 #endif /* HAVE_IODBCINST_H */
