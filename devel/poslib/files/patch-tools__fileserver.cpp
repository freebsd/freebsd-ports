--- tools/fileserver.cpp.orig
+++ tools/fileserver.cpp
@@ -32,6 +32,7 @@
 #include <sys/types.h>
 #include <dirent.h>
 #include <errno.h>
+#include <limits.h>
 
 DnsMessage *my_handle_query(pending_query *query);
 
