--- src/gdb.c.orig	2026-09-26 21:23:37 UTC
+++ src/gdb.c
@@ -39,13 +39,6 @@
 
 #include "top-config.h"
 
-// for addrinfo, struct timeval
-#define _POSIX_C_SOURCE 200112L
-// For strsep
-#define _DEFAULT_SOURCE
-#define _BSD_SOURCE
-#define _DARWIN_C_SOURCE
-
 #include <assert.h>
 #include <ctype.h>
 #include <errno.h>
@@ -65,6 +58,7 @@
 #include <fcntl.h>
 #include <netdb.h>
 #include <arpa/inet.h>
+#include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <sys/select.h>
 #include <sys/socket.h>
