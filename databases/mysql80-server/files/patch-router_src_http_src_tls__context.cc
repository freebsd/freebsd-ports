--- router/src/http/src/tls_context.cc.orig	2019-09-20 08:30:51 UTC
+++ router/src/http/src/tls_context.cc
@@ -91,7 +91,7 @@ static constexpr int o11x_version(TlsVersion version) 
       return TLS1_1_VERSION;
     case TlsVersion::TLS_1_2:
       return TLS1_2_VERSION;
-#if OPENSSL_VERSION_NUMBER >= ROUTER_OPENSSL_VERSION(1, 1, 1)
+#ifdef TLS1_3_VERSION
     case TlsVersion::TLS_1_3:
       return TLS1_3_VERSION;
 #endif
@@ -121,9 +121,11 @@ void TlsContext::version_range(TlsVersion min_version,
     default:
       // unknown, leave all disabled
       // fallthrough
+#ifdef TLS1_3_VERSION
     case TlsVersion::TLS_1_3:
       opts |= SSL_OP_NO_TLSv1_2;
       // fallthrough
+#endif
     case TlsVersion::TLS_1_2:
       opts |= SSL_OP_NO_TLSv1_1;
       // fallthrough
@@ -170,8 +172,10 @@ TlsVersion TlsContext::min_version() const {
       return TlsVersion::TLS_1_1;
     case TLS1_2_VERSION:
       return TlsVersion::TLS_1_2;
+#ifdef TLS1_3_VERSION
     case TLS1_3_VERSION:
       return TlsVersion::TLS_1_3;
+#endif
     case 0:
       return TlsVersion::AUTO;
     default:
