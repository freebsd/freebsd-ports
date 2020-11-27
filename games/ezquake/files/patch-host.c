--- host.c.orig	2020-09-16 22:08:02 UTC
+++ host.c
@@ -333,11 +333,19 @@ void SYSINFO_Init(void)
 	SYSINFO_processor_description = cpu_model;
 
 	gettimeofday(&old_tp, NULL);
+#ifdef __powerpc64__
+	__asm__ __volatile__("mfspr %%r3, 268": "=r" (old_tsc));
+#else
 	old_tsc = rdtsc();
+#endif
 	do {
 		gettimeofday(&tp, NULL);
 	} while ((tp.tv_sec - old_tp.tv_sec) * 1000000. + tp.tv_usec - old_tp.tv_usec < 1000000.);
+#ifdef __powerpc64__
+	__asm__ __volatile__("mfspr %%r3, 268": "=r" (tsc_freq));
+#else
 	tsc_freq = rdtsc();
+#endif
 	SYSINFO_MHz = (int)((tsc_freq - old_tsc) /
 						(tp.tv_sec - old_tp.tv_sec + (tp.tv_usec - old_tp.tv_usec) / 1000000.) /
 						1000000. + .5);
@@ -351,7 +359,7 @@ void SYSINFO_Init(void)
 		SYSINFO_3D_description = Q_strdup(gl_renderer);
 	}
 
-	snprintf(f_system_string, sizeof(f_system_string), "%lluMB", (int)(SYSINFO_memory / 1024LLU / 1024LLU));
+	snprintf(f_system_string, sizeof(f_system_string), "%lluMB", SYSINFO_memory / 1024LLU / 1024LLU);
 
 	if (SYSINFO_processor_description) {
 		strlcat(f_system_string, ", ", sizeof(f_system_string));
