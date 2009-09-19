--- src/xz/hardware.c~	2009-08-18 08:15:18.000000000 +0200
+++ src/xz/hardware.c	2009-08-18 08:17:50.000000000 +0200
@@ -42,12 +42,12 @@
 static void
 hardware_cores(void)
 {
-#if defined(HAVE_NUM_PROCESSORS_SYSCONF)
+#if defined(HAVE_NCPU_SYSCONF)
 	const long cpus = sysconf(_SC_NPROCESSORS_ONLN);
 	if (cpus > 0)
 		opt_threads = (size_t)(cpus);
 
-#elif defined(HAVE_NUM_PROCESSORS_SYSCTL)
+#elif defined(HAVE_NCPU_SYSCTL)
 	int name[2] = { CTL_HW, HW_NCPU };
 	int cpus;
 	size_t cpus_size = sizeof(cpus);
