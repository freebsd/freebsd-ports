--- sysdeps/freebsd/sysinfo.c.orig	Fri Nov 24 02:36:12 2006
+++ sysdeps/freebsd/sysinfo.c	Fri Nov 24 02:57:37 2006
@@ -73,6 +73,10 @@ init_sysinfo (glibtop *server)
 		g_hash_table_insert (cpuinfo->values, "vendor_id",
 				     g_strdup(model));
 
+		g_ptr_array_add (cpuinfo->labels, "model name");
+		g_hash_table_insert (cpuinfo->values, "model name",
+				     g_strdup(model));
+
 		g_ptr_array_add (cpuinfo->labels, "cpu MHz");
 		g_hash_table_insert (cpuinfo->values, "cpu MHz",
 				     g_strdup_printf("%d", mhz));
