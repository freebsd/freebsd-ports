--- include/private/gcconfig.h.orig	2016-08-08 20:30:40 UTC
+++ include/private/gcconfig.h
@@ -2745,11 +2745,6 @@
 # define SUNOS5SIGS
 #endif
 
-#ifdef DATASTART_USES_BSDGETDATASTART
-  GC_INNER ptr_t GC_FreeBSDGetDataStart(size_t, ptr_t);
-# define DATASTART_IS_FUNC
-#endif
-
 #if !defined(GC_EXPLICIT_SIGNALS_UNBLOCK) && defined(SUNOS5SIGS) \
     && !defined(GC_NO_PTHREAD_SIGMASK)
 # define GC_EXPLICIT_SIGNALS_UNBLOCK
