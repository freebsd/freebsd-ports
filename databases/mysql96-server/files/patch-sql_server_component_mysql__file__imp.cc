--- sql/server_component/mysql_file_imp.cc.orig
+++ sql/server_component/mysql_file_imp.cc
@@ -19,6 +19,7 @@
 #include "sql/server_component/mysql_file_imp.h"
 
 #include <fcntl.h>
+#include <sys/stat.h>
 #include <mysql/components/service_implementation.h>
 #include "my_io.h"
 #include "my_sys.h"

