--- ncbi-vdb/libs/kns/manager.c.orig	2023-07-10 16:13:36 UTC
+++ ncbi-vdb/libs/kns/manager.c
@@ -58,7 +58,7 @@
 #if HAVE_GNU_LIBC_VERSION_H
 #include <gnu/libc-version.h>
 #endif
-#if LINUX
+#if BSD || LINUX
 #include <arpa/inet.h>
 #include <netinet/in.h>
 #endif
