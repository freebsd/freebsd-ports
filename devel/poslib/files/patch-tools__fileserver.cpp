--- tools/fileserver.cpp.orig	2003-03-24 19:59:39 UTC
+++ tools/fileserver.cpp
@@ -32,6 +32,7 @@
 #include <sys/types.h>
 #include <dirent.h>
 #include <errno.h>
+#include <limits.h>
 
 DnsMessage *my_handle_query(pending_query *query);
 
