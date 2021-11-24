--- src/misc.c.orig	2020-11-20 21:36:33 UTC
+++ src/misc.c
@@ -378,6 +378,7 @@ gchar *get_symbolic_link(const gchar *path_utf8)
 
 gint get_cpu_cores(void)
 {
+	return 1;
 	FILE *cpuinfo = fopen("/proc/cpuinfo", "rb");
 	char *arg = 0;
 	size_t size = 0;
