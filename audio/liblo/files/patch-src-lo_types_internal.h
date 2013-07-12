--- src/lo_types_internal.h.orig	2013-05-22 18:34:31.000000000 +0200
+++ src/lo_types_internal.h	2013-06-24 01:54:53.000000000 +0200
@@ -20,6 +20,7 @@
 #else
 #define closesocket close
 #include <netdb.h>
+#include <netinet/in.h>
 #include <arpa/inet.h>
 #endif
 
@@ -33,6 +34,7 @@
 
 #ifdef ENABLE_THREADS
 #include <pthread.h>
+#include <sys/socket.h>
 #endif
 
 #include "lo/lo_osc_types.h"
