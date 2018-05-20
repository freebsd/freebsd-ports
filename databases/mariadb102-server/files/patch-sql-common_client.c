--- sql-common/client.c.orig	2018-01-03 14:48:29.000000000 +0100
+++ sql-common/client.c	2018-01-24 00:45:11.194419000 +0100
@@ -104,6 +104,10 @@
 #define CONNECT_TIMEOUT 0
 #endif
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) || defined(HAVE_YASSL)
+#define ASN1_STRING_get0_data(X) ASN1_STRING_data(X)
+#endif
+
 #include "client_settings.h"
 #include <ssl_compat.h>
 #include <sql_common.h>
