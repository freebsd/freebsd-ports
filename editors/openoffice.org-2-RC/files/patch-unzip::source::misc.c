--- work/oo_641c_src/unzip/source/misc.c.orig	Tue Mar  5 18:52:16 2002
+++ work/oo_641c_src/unzip/source/misc.c	Tue Mar  5 18:53:03 2002
@@ -301,8 +301,8 @@
     int yr, mo, dy, hh, mm, ss, leap;
     long m_time, days=0;
 #if (!defined(MACOS) && !defined(MSC) && !defined(__GO32__))
-#if (defined(BSD) || defined(MTS))
-#ifndef __386BSD__
+#if (defined(BSD) || defined(MTS) || defined(FREEBSD))
+#if !defined __386BSD__ && !defined FREEBSD
     static struct timeb tbp;
 #endif /* __386BSD__ */
 #else /* !(BSD || MTS) */
@@ -340,8 +340,8 @@
       /* - 1;   MS-DOS times always rounded up to nearest even second */
 
 #if (!defined(MACOS) && !defined(__GO32__))
-#if (defined(BSD) || defined(MTS) || defined (ALPHA)) && ! defined(MACOSX) && ! defined(NETBSD)
-#ifndef __386BSD__
+#if (defined(BSD) || defined(FREEBSD) || defined(MTS) || defined (ALPHA)) && ! defined(MACOSX) && ! defined(NETBSD)
+#if !defined __386BSD__ && !defined FREEBSD
     ftime(&tbp);
     m_time += tbp.timezone * 60L;
 #endif
