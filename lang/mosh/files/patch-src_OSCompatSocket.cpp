--- src/OSCompatSocket.cpp.orig	2024-10-28 01:31:37 UTC
+++ src/OSCompatSocket.cpp
@@ -33,7 +33,7 @@
 #define _DARWIN_C_SOURCE 1
 #elif defined(__NetBSD__)
 #define _NETBSD_SOURCE 1
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
 #define _BSD_SOURCE 1
 #elif !defined(_WIN32) && !defined(MONA) && !defined(__DragonFly__)
 #define _POSIX_C_SOURCE 200809L // for addrinfo (POSIX 2001)
