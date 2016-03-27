--- src/net/fusenshisslclientsocket.cpp.orig	2007-04-02 10:44:52 UTC
+++ src/net/fusenshisslclientsocket.cpp
@@ -52,9 +52,6 @@ bool FusenshiSSLClientSocket::connect(un
 {
     // 通信を暗号化しますが、ホストの証明は行いません。
     int ret;
-	const int cert_priority[] = {
-		GNUTLS_CRT_X509, 0
-	};
 
     if (NULL != m_session) close();
     
@@ -64,7 +61,6 @@ bool FusenshiSSLClientSocket::connect(un
         
 		gnutls_init(&m_session, GNUTLS_CLIENT);
 		gnutls_set_default_priority(m_session);
-		gnutls_certificate_type_set_priority(m_session, cert_priority);
 
 		gnutls_credentials_set(m_session, GNUTLS_CRD_CERTIFICATE, cert);
 		
