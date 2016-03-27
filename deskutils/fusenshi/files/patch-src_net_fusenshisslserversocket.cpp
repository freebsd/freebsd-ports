--- src/net/fusenshisslserversocket.cpp.orig	2007-04-02 10:44:52 UTC
+++ src/net/fusenshisslserversocket.cpp
@@ -56,9 +56,6 @@ public:
     bool sslAccept(int sock)
     {
     	int ret;
-		const int cert_priority[] = {
-			GNUTLS_CRT_X509, 0
-		};
 
         m_socket = sock;
 
@@ -69,8 +66,7 @@ public:
         if (!cert) return false;
 
 		gnutls_init(&m_session, GNUTLS_SERVER);
-		gnutls_set_default_export_priority(m_session);
-		gnutls_certificate_type_set_priority(m_session, cert_priority);
+		gnutls_set_default_priority(m_session);
 
 		gnutls_credentials_set(m_session, GNUTLS_CRD_CERTIFICATE, cert);
 		gnutls_certificate_server_set_request(m_session, GNUTLS_CERT_REQUIRE);
