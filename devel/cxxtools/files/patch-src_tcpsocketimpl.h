--- src/tcpsocketimpl.h.orig	2014-01-17 19:05:09 UTC
+++ src/tcpsocketimpl.h
@@ -36,6 +36,7 @@
 #include <string>
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #include <sys/poll.h>
 #include <sys/time.h>
 #include <netinet/in.h>
