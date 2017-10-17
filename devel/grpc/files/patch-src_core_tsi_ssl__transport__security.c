--- src/core/tsi/ssl_transport_security.c.orig	2017-10-05 19:05:39 UTC
+++ src/core/tsi/ssl_transport_security.c
@@ -20,6 +20,7 @@
 
 #include <grpc/support/port_platform.h>
 
+#include <sys/socket.h>
 #include <limits.h>
 #include <string.h>
 
@@ -54,11 +55,10 @@
 #define TSI_SSL_MAX_PROTECTED_FRAME_SIZE_UPPER_BOUND 16384
 #define TSI_SSL_MAX_PROTECTED_FRAME_SIZE_LOWER_BOUND 1024
 
-/* Putting a macro like this and littering the source file with #if is really
-   bad practice.
-   TODO(jboeuf): refactor all the #if / #endif in a separate module. */
-#ifndef TSI_OPENSSL_ALPN_SUPPORT
+#if OPENSSL_VERSION_NUMBER >= 0x10002000L
 #define TSI_OPENSSL_ALPN_SUPPORT 1
+#else
+#define TSI_OPENSSL_ALPN_SUPPORT 0
 #endif
 
 /* TODO(jboeuf): I have not found a way to get this number dynamically from the
