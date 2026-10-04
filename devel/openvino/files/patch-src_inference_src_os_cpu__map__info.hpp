--- src/inference/src/os/cpu_map_info.hpp.orig	2026-04-10 00:35:51 UTC
+++ src/inference/src/os/cpu_map_info.hpp
@@ -71,7 +71,7 @@ CPU& cpu_info();
 
 CPU& cpu_info();
 
-#ifdef __linux__
+#ifdef __FreeBSD__
 /**
  * @brief      Parse nodes information to update _sockets, proc_type_table and cpu_mapping_table on Linux
  * @param[in]  node_info_table nodes information for this platform.
