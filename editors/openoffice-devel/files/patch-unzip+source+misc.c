--- ../unzip/source/misc.c.orig	Sat Apr  6 12:13:38 2002
+++ ../unzip/source/misc.c	Wed May  1 22:36:32 2002
@@ -300,7 +300,7 @@
     static short yday[]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
     int yr, mo, dy, hh, mm, ss, leap;
     long m_time, days=0;
-#if (!defined(MACOS) && !defined(MSC) && !defined(__GO32__) && !defined(NETBSD))
+#if (!defined(MACOS) && !defined(MSC) && !defined(__GO32__) && !defined(NETBSD) && !defined(FREEBSD))
 #if (defined(BSD) || defined(MTS))
 #ifndef __386BSD__
     static struct timeb tbp;
