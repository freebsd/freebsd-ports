--- src/lo_types_internal.h.orig	2013-07-25 10:14:32 UTC
+++ src/lo_types_internal.h
@@ -20,6 +20,7 @@
 #else
 #define closesocket close
 #include <netdb.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #endif
 
@@ -33,6 +34,7 @@ typedef __int32 int32_t;
 
 #ifdef ENABLE_THREADS
 #include <pthread.h>
+#include <sys/socket.h>
 #endif
 
 #include "lo/lo_osc_types.h"
