--- ./src/FCConfig.h.orig	Sat Feb 24 11:44:55 2007
+++ ./src/FCConfig.h	Sun Apr 22 22:02:51 2007
@@ -71,8 +71,10 @@
 //#	endif
 //#elif defined(hpux) || defined(__hpux) || defined(__hpux__)
 //#	define FC_OS_HPUX_
-//#elif defined(__FreeBSD__)
-//#	define FC_OS_FREEBSD
+#elif defined(__FreeBSD__)
+#	ifndef FC_OS_FREEBSD
+#	define FC_OS_FREEBSD
+#	endif
 //#elif defined(__NetBSD__)
 //#	define FC_OS_NETBSD
 //#elif defined(__OpenBSD__)
@@ -159,6 +161,11 @@
 #	define _WINDOWS
 #	endif
 #endif
+
+#ifdef FC_OS_FREEBSD
+#	define FREEBSD
+#endif
+
 
 #ifdef FC_OS_LINUX
 #	define LIN
