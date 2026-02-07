--- host.c.orig	2021-02-09 17:35:52 UTC
+++ host.c
@@ -333,16 +333,30 @@ void SYSINFO_Init(void)
 	SYSINFO_processor_description = cpu_model;
 
 	gettimeofday(&old_tp, NULL);
+#if defined(__powerpc__) || defined(__i386__) || defined(__amd64__)
+#ifdef __powerpc__
+	__asm__ __volatile__("mfspr %%r3, 268": "=r" (old_tsc));
+#else
 	old_tsc = rdtsc();
+#endif
 	do {
 		gettimeofday(&tp, NULL);
 	} while ((tp.tv_sec - old_tp.tv_sec) * 1000000. + tp.tv_usec - old_tp.tv_usec < 1000000.);
+#ifdef __powerpc__
+	__asm__ __volatile__("mfspr %%r3, 268": "=r" (tsc_freq));
+#else
 	tsc_freq = rdtsc();
+#endif
 	SYSINFO_MHz = (int)((tsc_freq - old_tsc) /
 						(tp.tv_sec - old_tp.tv_sec + (tp.tv_usec - old_tp.tv_usec) / 1000000.) /
 						1000000. + .5);
 // VVD: We can use sysctl hw.clockrate, but it don't work on i486 - always 0.
 // Must work on Pentium 1/2/3; tested on Pentium 4. And RELENG_4 have no this sysctl.
+#else
+	len = sizeof(val);
+	sysctlbyname("dev.cpu.0.freq", &val, &len, NULL, 0);
+	SYSINFO_MHz = val;
+#endif
 
 	if (gl_renderer  &&  gl_renderer[0]) {
 		if (SYSINFO_3D_description != NULL) {
@@ -351,7 +365,7 @@ void SYSINFO_Init(void)
 		SYSINFO_3D_description = Q_strdup(gl_renderer);
 	}
 
-	snprintf(f_system_string, sizeof(f_system_string), "%lluMB", (int)(SYSINFO_memory / 1024LLU / 1024LLU));
+	snprintf(f_system_string, sizeof(f_system_string), "%lluMB", SYSINFO_memory / 1024LLU / 1024LLU);
 
 	if (SYSINFO_processor_description) {
 		strlcat(f_system_string, ", ", sizeof(f_system_string));
