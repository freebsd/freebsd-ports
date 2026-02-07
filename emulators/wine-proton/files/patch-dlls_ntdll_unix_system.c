--- dlls/ntdll/unix/system.c.orig	2024-04-26 15:24:41 UTC
+++ dlls/ntdll/unix/system.c
@@ -574,6 +574,7 @@ static void get_cpuinfo( SYSTEM_CPU_INFORMATION *info 
 
 #endif /* End architecture specific feature detection for CPUs */
 
+#ifdef __linux__
 static void fill_performance_core_info(void);
 static BOOL sysfs_parse_bitmap(const char *filename, ULONG_PTR *mask);
 
@@ -712,6 +713,12 @@ error:
     cpu_override.mapping.cpu_count = 0;
     ERR("Invalid WINE_CPU_TOPOLOGY string %s (%s).\n", debugstr_a(env_override), debugstr_a(s));
 }
+#else
+static void fill_cpu_override(unsigned int)
+{
+    /* do nothing */
+}
+#endif
 
 struct cpu_topology_override *get_cpu_topology_override(void)
 {
