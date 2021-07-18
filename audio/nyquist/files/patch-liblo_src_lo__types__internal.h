--- liblo/src/lo_types_internal.h.orig	2021-04-18 05:50:40 UTC
+++ liblo/src/lo_types_internal.h
@@ -8,6 +8,7 @@
 #ifdef HAVE_SYS_SOCKET_H
 #include <sys/types.h>
 #include <sys/socket.h>
+#include <netinet/in.h>
 #endif
 
 #ifdef HAVE_POLL
