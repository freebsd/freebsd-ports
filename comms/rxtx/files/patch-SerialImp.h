$FreeBSD$

--- src/SerialImp.h.orig	Sat Apr 24 23:31:27 2004
+++ src/SerialImp.h	Sat Apr 24 23:31:38 2004
@@ -126,7 +126,7 @@
 #endif /* __sgi__ || sgi */
 #if defined(__FreeBSD__)
 #	define DEVICEDIR "/dev/"
-#	define LOCKDIR "/var/spool/uucp"
+#	define LOCKDIR "/var/spool/lock"
 #	define LOCKFILEPREFIX "LK."
 #	define UUCP
 #endif
