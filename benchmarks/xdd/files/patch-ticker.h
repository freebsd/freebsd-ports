--- ticker.h.orig	Fri Mar 16 06:44:32 2007
+++ ticker.h	Fri Mar 16 06:44:41 2007
@@ -35,7 +35,7 @@
 /* Types */
 /* ----- */
 /* A ticker value */
-#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX)
+#if (LINUX || AIX || IRIX || SOLARIS || HPUX || ALTIX || OSX || FreeBSD)
 typedef unsigned long long tick_t;
 #else
 typedef unsigned __int64  tick_t;
