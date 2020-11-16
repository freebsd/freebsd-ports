--- host.c.orig
+++ host.c
@@ -351,7 +351,7 @@
 		SYSINFO_3D_description = Q_strdup(gl_renderer);
 	}
 
-	snprintf(f_system_string, sizeof(f_system_string), "%lluMB", (int)(SYSINFO_memory / 1024LLU / 1024LLU));
+	snprintf(f_system_string, sizeof(f_system_string), "%lluMB", SYSINFO_memory / 1024LLU / 1024LLU);
 
 	if (SYSINFO_processor_description) {
 		strlcat(f_system_string, ", ", sizeof(f_system_string));
