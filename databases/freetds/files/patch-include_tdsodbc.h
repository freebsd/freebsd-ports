--- include/tdsodbc.h.orig	2015-01-29 00:40:17 UTC
+++ include/tdsodbc.h
@@ -30,8 +30,8 @@
 #include <odbcinst.h>
 #endif
 #else /* IODBC */
-#include <isql.h>
-#include <isqlext.h>
+#include <libiodbc/isql.h>
+#include <libiodbc/isqlext.h>
 #ifdef HAVE_IODBCINST_H
 #include <iodbcinst.h>
 #endif /* HAVE_IODBCINST_H */
