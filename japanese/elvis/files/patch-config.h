--- config.h.orig	Fri Nov 29 03:24:51 2002
+++ config.h	Fri Nov 29 03:29:12 2002
@@ -60,6 +60,10 @@
 # endif
 #endif
 
+#ifdef __FreeBSD__
+# define HAVE_MEMCPY	1
+#endif
+
 /* Microsoft C: sorry, Watcom does the same thing */
 #ifdef	M_I86
 # ifndef M_SYSV
