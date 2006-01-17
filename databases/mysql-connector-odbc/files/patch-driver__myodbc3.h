--- driver/myodbc3.h.orig	Sun Oct  9 22:33:40 2005
+++ driver/myodbc3.h	Thu Oct 27 16:16:05 2005
@@ -101,7 +101,12 @@
 #include <ltdl.h>
 #include <sql.h>
 #include <sqlext.h>
+
+# if defined(HAVE_IODBCINST_H)
+#include <iodbcinst.h>
+#elif defined(HAVE_ODBCINST_H)
 #include <odbcinst.h>
+# endif
 
 #ifndef SYSTEM_ODBC_INI
 #define BOTH_ODBC_INI ODBC_BOTH_DSN
