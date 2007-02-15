--- kexi/migration/pqxx/pqxxmigrate.h.orig	Sun Feb 11 17:15:12 2007
+++ kexi/migration/pqxx/pqxxmigrate.h	Sun Feb 11 17:15:38 2007
@@ -26,7 +26,7 @@
 #include <kexidb/field.h>
 #include <kexidb/connection.h>
 
-#include <pqxx/all.h>
+#include <pqxx/pqxx>
 
 namespace KexiMigration
 {
