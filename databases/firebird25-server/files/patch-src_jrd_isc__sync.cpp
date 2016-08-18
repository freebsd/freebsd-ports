--- src/jrd/isc_sync.cpp.orig	2016-06-30 09:34:54 UTC
+++ src/jrd/isc_sync.cpp
@@ -677,7 +677,7 @@ namespace {
 	public:
 		const static int N_FILES = 128;
 		const static int N_SETS = 256;
-#if defined(DEV_BUILD)
+#if defined(DEV_BUILD) || defined(FREEBSD)
 		const static int SEM_PER_SET = 4;	// force multiple sets allocation
 #else
 		const static int SEM_PER_SET = 31;	// hard limit for some old systems, might set to 32
