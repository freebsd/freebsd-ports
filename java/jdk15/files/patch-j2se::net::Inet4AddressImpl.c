$FreeBSD$

--- ../../j2se/src/solaris/native/java/net/Inet4AddressImpl.c	10 Aug 2005 16:51:14 -0000	1.8
+++ ../../j2se/src/solaris/native/java/net/Inet4AddressImpl.c	21 Sep 2005 02:27:28 -0000	1.9
@@ -608,6 +608,8 @@
     return ret;
 }
 
+#endif /* USE_GETADDRINFO */
+
 #define SET_NONBLOCKING(fd) {		\
         int flags = fcntl(fd, F_GETFL);	\
         flags |= O_NONBLOCK; 		\
@@ -860,6 +862,7 @@
     }
 }
 
+#ifndef USE_GETADDRINFO
 #if defined(_ALLBSD_SOURCE)
 
 #if defined(LIBC_SCCS) && !defined(lint)
@@ -1069,4 +1072,4 @@
 #endif /* !defined(_REENTRANT) || !defined(DO_PTHREADS) */
 
 #endif
-#endif /* USE_GETADDRINFO */
+#endif /* !USE_GETADDRINFO */
