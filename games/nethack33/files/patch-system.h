--- include/system.h.orig	Mon Apr 19 23:27:53 2004
+++ include/system.h	Mon Apr 19 23:31:54 2004
@@ -86,7 +86,7 @@
 # endif
 #else
 E long lrand48();
-E void srand48();
+E void FDECL(srand48, (long));
 #endif /* BSD || ULTRIX || RANDOM */
 
 #if !defined(BSD) || defined(ultrix)
@@ -340,10 +340,10 @@
 #if defined(BSD) && defined(ultrix)	/* i.e., old versions of Ultrix */
 E void sleep();
 #endif
-#if defined(ULTRIX) || defined(SYSV)
+#if !defined(__FreeBSD__) && (defined(ULTRIX) || defined(SYSV))
 E unsigned sleep();
 #endif
-#if defined(HPUX)
+#if defined(HPUX) || defined(__FreeBSD__)
 E unsigned int FDECL(sleep, (unsigned int));
 #endif
 #ifdef VMS
