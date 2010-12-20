--- src/jrd/isc_sync.cpp	2010-12-18 21:08:26.000000000 -0500
+++ src/jrd/isc_sync.cpp	2010-12-18 21:09:05.000000000 -0500
@@ -320,7 +320,7 @@
 	public:
 		const static int N_FILES = 8;
 		const static int N_SETS = 256;
-#ifdef DEV_BUILD
+#if defined(DEV_BUILD) || defined(FREEBSD)
 		const static int SEM_PER_SET = 4;	// force multiple sets allocation
 #else
 		const static int SEM_PER_SET = 31;	// hard limit for some old systems, might set to 32
