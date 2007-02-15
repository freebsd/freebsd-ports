--- kexi/kexidb/drivers/pqxx/pqxxconnection_p.h.orig	Sun Feb 11 16:52:10 2007
+++ kexi/kexidb/drivers/pqxx/pqxxconnection_p.h	Sun Feb 11 16:54:21 2007
@@ -31,7 +31,7 @@
 #define PQXXSQLCONNECTIONINTERNAL_H
 
 #include <kexidb/connection_p.h>
-#include <pqxx/all.h>
+#include <pqxx/pqxx>
 
 namespace KexiDB
 {
