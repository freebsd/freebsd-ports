--- src/tds/tls.c.orig	2021-08-31 09:00:01 UTC
+++ src/tds/tls.c
@@ -53,6 +53,10 @@
 #include <sys/socket.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <sys/socket.h>
+#endif
+
 #include <freetds/tds.h>
 #include <freetds/utils/string.h>
 #include <freetds/tls.h>
@@ -63,7 +67,7 @@
 
 /**
  * \addtogroup network
- * @{ 
+ * @{
  */
 
 #if defined(HAVE_GNUTLS) || defined(HAVE_OPENSSL)
@@ -75,6 +79,15 @@
 #define SSL_PTR ptr
 #else
 
+#ifdef LIBRESSL_VERSION_NUMBER
+#if LIBRESSL_VERSION_NUMBER < 0x2070000FL
+static pthread_mutex_t *openssllocks;
+#undef OPENSSL_VERSION_NUMBER
+#define OPENSSL_VERSION_NUMBER 0x1000107fL
+#endif
+#define TLS_ST_OK SSL_ST_OK
+#endif
+
 /* some compatibility layer */
 #if !HAVE_BIO_GET_DATA
 static inline void
@@ -115,7 +128,7 @@ tds_pull_func_login(SSL_PULL_ARGS)
 	int have;
 
 	tdsdump_log(TDS_DBG_FUNC, "in tds_pull_func_login\n");
-	
+
 	/* here we are initializing (crypted inside TDS packets) */
 
 	/* if we have some data send it */
@@ -450,7 +463,7 @@ tds_ssl_init(TDSSOCKET *tds)
 	const char *tls_msg;
 
 	xcred = NULL;
-	session = NULL;	
+	session = NULL;
 	tls_msg = "initializing tls";
 
 	if (!tls_initialized) {
@@ -826,18 +839,25 @@ check_name_match(ASN1_STRING *name, const char *hostna
 static int
 check_name_match(ASN1_STRING *name, const char *hostname)
 {
-	char *name_utf8 = NULL;
+	char *name_utf8 = NULL, *tmp_name;
 	int ret, name_len;
 
 	name_len = ASN1_STRING_to_UTF8((unsigned char **) &name_utf8, name);
 	if (name_len < 0)
 		return 0;
 
+    tmp_name = tds_strndup(name_utf8, name_len);
+    OPENSSL_free(name_utf8);
+    if (!tmp_name)
+        return 0;
+
+    name_utf8 = tmp_name;
+
 	tdsdump_log(TDS_DBG_INFO1, "Got name %s\n", name_utf8);
 	ret = 0;
 	if (strlen(name_utf8) == name_len && check_wildcard(name_utf8, hostname))
 		ret = 1;
-	OPENSSL_free(name_utf8);
+	free(name_utf8);
 	return ret;
 }
 
@@ -1095,4 +1115,3 @@ tds_ssl_deinit(TDSCONNECTION *conn)
 
 #endif
 /** @} */
-
