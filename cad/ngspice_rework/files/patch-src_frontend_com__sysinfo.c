--- src/frontend/com_sysinfo.c.orig	2020-05-06 06:11:56 UTC
+++ src/frontend/com_sysinfo.c
@@ -396,18 +396,6 @@ static void set_static_system_info(void)
     return;
 } /* end of function set_static_system_info */
 
-#elif defined(__APPLE__) && defined(__MACH__)
-/* Get memory information */
-static int get_sysmem(struct sys_memory *memall)
-{
-    fprintf(stderr, "System memory info is not available\n");
-    return -1;
-}
-/* Get system information */
-static void set_static_system_info(void)
-{
-}
-
 #elif defined(_WIN32)
 
 /* Get memory information */
@@ -972,9 +960,14 @@ static void get_physical_processor_count(void)
     return;
 } /* end of function get_physical_processor_count */
 
+#else /* no Windows OS, no proc info file system */
 
+static int get_sysmem(struct sys_memory *memall)
+{
+    fprintf(stderr, "System memory info is not available\n");
+    return -1;
+}
 
-#else /* no Windows OS, no proc info file system */
 void set_static_system_info(void)
 {
     /* Set to no data available */
