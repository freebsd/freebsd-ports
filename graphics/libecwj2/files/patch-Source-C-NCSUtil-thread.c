--- Source/C/NCSUtil/thread.c.orig	2006-07-03 05:15:02.000000000 +0400
+++ Source/C/NCSUtil/thread.c	2010-07-29 17:20:43.000000000 +0400
@@ -838,13 +838,13 @@
 	yield();
 #elif defined(HPUX)
 	sched_yield();
-#elif defined(LINUX)
+#elif defined(LINUX) || defined (FREEBSD)
 	sched_yield();
 	//pthread_yield();
 #elif defined(MACOSX)
 	pthread_yield_np();
 #else
-ERROR: NCSThreadYield() needs coding in NCSUtil/thread.c
+#error NCSThreadYield() needs coding in NCSUtil/thread.c
 #endif
 	       return(FALSE);
 }
@@ -1525,7 +1525,7 @@
 UINT32 NCSGetNumCPUs(void)
 {
 
-	UINT32 ncpus = 1;
+	UINT32 ncpus;
 
 #ifdef WIN32
 #if !defined(_WIN32_WCE)&&defined(_X86_)
@@ -1545,15 +1545,13 @@
 		GetSystemInfo(&si);
 		ncpus = (UINT32)si.dwNumberOfProcessors;		
 	}
-#else
-#ifdef SOLARIS
+#elif defined SOLARIS
 	long n;
 	n = sysconf(_SC_NPROCESSORS_ONLN);
 	if(n > 0) {
 		ncpus = n;
 	}
-#else
-#ifdef HPUX
+#elif defined HPUX
 #include <sys/param.h>
 #include <sys/pstat.h>
 
@@ -1564,16 +1562,23 @@
 		fprintf(stderr, "NCSGetNumCPUs() : value not tested [%d]\n",psd.psd_proc_cnt);
 		return (psd.psd_proc_cnt);
 	}
-#else
-#ifdef LINUX
+#elif defined LINUX
 	long n;
 	n = sysconf(_SC_NPROCESSORS_ONLN);
 	if(n > 0) {
 		ncpus = n;
 	}
-#endif
-#endif
-#endif
+#elif defined FREEBSD
+#include <sys/sysctl.h>
+	int mib[2];
+	size_t len;
+
+	mib[0] = CTL_HW;
+	mib[1] = HW_NCPU;
+	len = sizeof(ncpus);
+	sysctl(mib, 2, &ncpus, &len, NULL, 0);
+#else
+#error NCSGetNumCPUs() needs coding
 #endif
 
 	return(ncpus);
