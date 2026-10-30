--- sql/server_component/mysql_file_imp.cc.orig	2026-07-10 11:18:36 UTC
+++ sql/server_component/mysql_file_imp.cc
@@ -24,6 +24,7 @@ Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 #include "sql/server_component/mysql_file_imp.h"
 
 #include <fcntl.h>
+#include <sys/stat.h>
 #include <mysql/components/service_implementation.h>
 #include "my_io.h"
 #include "my_sys.h"
