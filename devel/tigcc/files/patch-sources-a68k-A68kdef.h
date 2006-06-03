--- sources/a68k/A68kdef.h.orig	Wed Feb  2 00:00:10 2005
+++ sources/a68k/A68kdef.h	Tue Mar 21 14:16:27 2006
@@ -38,11 +38,11 @@
 extern int  /*open(), creat(),*/ read(), write(), close(), unlink();
 /* (2.71.F3u) open, creat should be declared in fcntl.h and cause a conflict
               with GCC 3.4 */
-#if defined(__MACH__) && defined(__APPLE__) /* Darwin / OS X */
-/* On Darwin, the implicit declaration below won't work, so we need to include
+#if (defined(__MACH__) && defined(__APPLE__)) || defined (__OpenBSD__) || defined (__NetBSD__) || defined (__FreeBSD__) /* Darwin / OS X / BSD */
+/* On BSD/Darwin, the implicit declaration below won't work, so we need to include
    <unistd.h>. - v.2.71.F3j, Kevin Kofler (reported by Christian Walther) */
 #include <unistd.h>
-#else /* not Darwin / OS X */
+#else /* not Darwin / OS X /BSD */
 extern long lseek();
 #endif
 /* Win32 port in 2.71.F3a by Kevin Kofler for the TIGCC Team
