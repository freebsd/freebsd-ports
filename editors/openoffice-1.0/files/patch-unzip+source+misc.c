FreeBSD support
--- unzip/source/misc.c.orig	Mon Jul 15 14:25:32 2002
+++ unzip/source/misc.c	Mon Jul 15 14:27:15 2002
@@ -300,9 +300,9 @@
     static short yday[]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
     int yr, mo, dy, hh, mm, ss, leap;
     long m_time, days=0;
-#if (!defined(MACOS) && !defined(MSC) && !defined(__GO32__) && !defined(NETBSD))
-#if (defined(BSD) || defined(MTS) || defined(FREEBSD))
-#if !defined __386BSD__ && !defined FREEBSD
+#if (!defined(MACOS) && !defined(MSC) && !defined(__GO32__) && !defined(NETBSD) && !defined(FREEBSD))
+#if (defined(BSD) || defined(MTS)
+#if !defined __386BSD__
     static struct timeb tbp;
 #endif /* __386BSD__ */
 #else /* !(BSD || MTS) */
