--- src/Csocket.cpp.orig	2015-11-15 17:54:20 UTC
+++ src/Csocket.cpp
@@ -47,6 +47,7 @@
 #include <stdio.h>
 #include <openssl/conf.h>
 #include <openssl/engine.h>
+#include <openssl/comp.h>
 #endif /* HAVE_LIBSSL */
 
 #ifdef HAVE_ICU
@@ -1463,14 +1464,6 @@ bool Csock::SSLClientSetup()
 
 	switch( m_iMethod )
 	{
-	case SSL3:
-		m_ssl_ctx = SSL_CTX_new( SSLv3_client_method() );
-		if( !m_ssl_ctx )
-		{
-			CS_DEBUG( "WARNING: MakeConnection .... SSLv3_client_method failed!" );
-			return( false );
-		}
-		break;
 	case TLS12:
 #if defined( TLS1_2_VERSION ) && defined( OPENSSL_VERSION_NUMBER ) && OPENSSL_VERSION_NUMBER >= 0x1000100f
 		m_ssl_ctx = SSL_CTX_new( TLSv1_2_client_method() );
@@ -1510,6 +1503,17 @@ bool Csock::SSLClientSetup()
 		break;
 #endif /* OPENSSL_NO_SSL2 */
 		/* Fall through if SSL2 is disabled */
+#ifndef OPENSSL_NO_SSL3
+	case SSL3:
+		m_ssl_ctx = SSL_CTX_new( SSLv3_client_method() );
+		if( !m_ssl_ctx )
+		{
+			CS_DEBUG( "WARNING: MakeConnection .... SSLv3_client_method failed!" );
+			return( false );
+		}
+		break;
+#endif /* OPENSSL_NO_SSL3 */
+		/* Fall through if SSL3 is disabled */
 	case SSL23:
 	default:
 		if( m_iMethod != SSL23 )
@@ -1585,14 +1589,6 @@ SSL_CTX * Csock::SetupServerCTX()
 	SSL_CTX * pCTX = NULL;
 	switch( m_iMethod )
 	{
-	case SSL3:
-		pCTX = SSL_CTX_new( SSLv3_server_method() );
-		if( !pCTX )
-		{
-			CS_DEBUG( "WARNING: MakeConnection .... SSLv3_server_method failed!" );
-			return( NULL );
-		}
-		break;
 	case TLS12:
 #if defined( TLS1_2_VERSION ) && defined( OPENSSL_VERSION_NUMBER ) && OPENSSL_VERSION_NUMBER >= 0x1000100f
 		pCTX = SSL_CTX_new( TLSv1_2_server_method() );
@@ -1632,6 +1628,17 @@ SSL_CTX * Csock::SetupServerCTX()
 		break;
 #endif /* OPENSSL_NO_SSL2 */
 		/* Fall through if SSL2 is disabled */
+#ifndef OPENSSL_NO_SSL3
+	case SSL3:
+		pCTX = SSL_CTX_new( SSLv3_server_method() );
+		if( !pCTX )
+		{
+			CS_DEBUG( "WARNING: MakeConnection .... SSLv3_server_method failed!" );
+			return( NULL );
+		}
+		break;
+#endif /* OPENSSL_NO_SSL3 */
+		/* Fall through if SSL3 is disabled */
 	case SSL23:
 	default:
 		if( m_iMethod != SSL23 )
