--- include/system.h.orig	Mon Nov  4 08:01:25 1996
+++ include/system.h	Sat Jun 19 16:18:02 1999
@@ -80,7 +80,7 @@
 # if !defined(SUNOS4) || defined(RANDOM)
 E void FDECL(srandom, (unsigned int));
 # else
-#  ifndef bsdi
+#  if !defined(bsdi) && !defined(__FreeBSD__)
 E int FDECL(srandom, (unsigned int));
 #  endif
 # endif
@@ -510,7 +510,7 @@
 # if defined(ULTRIX) || defined(SYSV) || defined(MICRO) || defined(VMS) || defined(MAC)
 E time_t FDECL(time, (time_t *));
 # else
-E long FDECL(time, (time_t *));
+E time_t FDECL(time, (time_t *));
 # endif /* ULTRIX */
 
 #ifdef VMS
