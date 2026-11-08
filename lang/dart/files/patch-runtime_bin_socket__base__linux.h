Include <netinet/in.h>, which glibc pulls in through <netdb.h> but
FreeBSD doesn't (series 0005).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/socket_base_linux.h.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/socket_base_linux.h
@@ -11,6 +11,7 @@
 
 #include <arpa/inet.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #include <sys/socket.h>
 #include <sys/un.h>
 
