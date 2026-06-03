--- components/group_replication_resource_manager/resource_manager_memory_stats.h.orig	2026-05-03 17:27:31.826021000 +0200
+++ components/group_replication_resource_manager/resource_manager_memory_stats.h	2026-05-03 17:28:14.232092000 +0200
@@ -6,6 +6,7 @@
 #define GR_RESOURCE_MANAGER_MEMORY_STATS
 
 #include <cerrno>
+#include <ctime>
 #include <cstdint>
 #include <cstring>
 #include <string>
