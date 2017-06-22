--- include/private/gcconfig.h.orig	2016-08-02 19:36:14 UTC
+++ include/private/gcconfig.h
@@ -176,7 +176,7 @@
 #      define EWS4800
 #    endif
 #    if !defined(LINUX) && !defined(EWS4800) && !defined(NETBSD) \
-        && !defined(OPENBSD)
+        && !defined(OPENBSD) && !defined(FREEBSD)
 #      if defined(ultrix) || defined(__ultrix)
 #        define ULTRIX
 #      else
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
