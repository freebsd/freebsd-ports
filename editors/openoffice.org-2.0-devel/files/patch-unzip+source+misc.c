--- ../unzip/source/misc.c.orig	Wed May  2 03:13:26 2001
+++ ../unzip/source/misc.c	Fri Oct 18 23:37:13 2002
@@ -300,7 +300,7 @@
     static short yday[]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
     int yr, mo, dy, hh, mm, ss, leap;
     long m_time, days=0;
-#if (!defined(MACOS) && !defined(MSC) && !defined(__GO32__))
+#if (!defined(MACOS) && !defined(MSC) && !defined(__GO32__) && !defined(FREEBSD))
 #if (defined(BSD) || defined(MTS))
 #ifndef __386BSD__
     static struct timeb tbp;
