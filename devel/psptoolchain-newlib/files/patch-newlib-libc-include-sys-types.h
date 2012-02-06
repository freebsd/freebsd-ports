--- ./newlib/libc/include/sys/types.h.orig	2011-08-01 17:22:18.000000000 +0000
+++ ./newlib/libc/include/sys/types.h	2012-01-25 19:33:12.000000000 +0000
@@ -200,6 +200,7 @@
 
 typedef unsigned short nlink_t;
 
+#if !defined(__psp__)
 /* We don't define fd_set and friends if we are compiling POSIX
    source, or if we have included (or may include as indicated
    by __USE_W32_SOCKETS) the W32api winsock[2].h header which
@@ -245,6 +246,7 @@
 }))
 
 # endif	/* !(defined (_POSIX_SOURCE) || defined (_WINSOCK_H) || defined (__USE_W32_SOCKETS)) */
+#endif /* !defined(__psp__) */
 
 #undef __MS_types__
 #undef _ST_INT32
