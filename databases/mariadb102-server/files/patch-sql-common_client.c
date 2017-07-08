--- sql-common/client.c.orig	2017-05-14 23:13:18 UTC
+++ sql-common/client.c
@@ -104,6 +104,10 @@ my_bool	net_flush(NET *net);
 #define CONNECT_TIMEOUT 0
 #endif
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L || defined(LIBRESSL_VERSION_NUMBER) || defined(HAVE_YASSL)
+#define ASN1_STRING_get0_data(X) ASN1_STRING_data(X)
+#endif
+
 #include "client_settings.h"
 #include <ssl_compat.h>
 #include <sql_common.h>
