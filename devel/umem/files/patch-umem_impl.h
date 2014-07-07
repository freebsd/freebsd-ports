--- umem_impl.h.orig	2014-07-04 11:29:34.393156748 -0700
+++ umem_impl.h	2014-07-04 11:29:54.599155604 -0700
@@ -255,12 +255,7 @@
 	int		cc_prounds;	/* number of objects in previous mag */
 	int		cc_magsize;	/* number of rounds in a full mag */
 	int		cc_flags;	/* CPU-local copy of cache_flags */
-#if (!defined(_LP64) || defined(UMEM_PTHREAD_MUTEX_TOO_BIG)) && !defined(_WIN32)
-	/* on win32, UMEM_CPU_PAD evaluates to zero, and the MS compiler
-	 * won't allow static initialization of arrays containing structures
-	 * that contain zero size arrays */
 	char		cc_pad[UMEM_CPU_PAD]; /* for nice alignment (32-bit) */
-#endif
 } umem_cpu_cache_t;
 
 /*
