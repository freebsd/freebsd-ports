--- ../unzip/source/misc.c.orig	Fri Feb 15 15:10:30 2002
+++ ../unzip/source/misc.c	Wed Apr  3 01:19:16 2002
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
