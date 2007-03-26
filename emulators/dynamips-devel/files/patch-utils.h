--- utils.h.orig	Wed Feb 14 20:37:58 2007
+++ utils.h	Tue Feb 20 18:56:54 2007
@@ -12,6 +12,8 @@
 #include <sys/time.h>
 #include <time.h>
 #include <netinet/in.h>
+#include <pthread.h>
+#include <signal.h>
 
 /* True/False definitions */
 #ifndef FALSE
@@ -35,6 +37,8 @@
 #elif defined(__i386) || defined(__i386__) || defined(i386)
 #define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
 #elif defined(__x86_64__)
+#define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
+#elif defined(__ia64__)
 #define ARCH_BYTE_ORDER ARCH_LITTLE_ENDIAN
 #endif
 
