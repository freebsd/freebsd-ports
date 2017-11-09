--- src/vendor/openssl-sys/src/lib.rs.orig	2017-10-09 21:52:49 UTC
+++ src/vendor/openssl-sys/src/lib.rs
@@ -1225,10 +1225,15 @@ pub const SSL_VERIFY_NONE: c_int = 0;
 pub const SSL_VERIFY_PEER: c_int = 1;
 pub const SSL_VERIFY_FAIL_IF_NO_PEER_CERT: c_int = 2;
 
-#[cfg(not(ossl101))]
+#[cfg(not(any(libressl261, libressl262, libressl263, ossl101)))]
 pub const SSL_OP_TLSEXT_PADDING: c_ulong = 0x00000010;
+#[cfg(any(libressl261, libressl262, libressl263))]
+pub const SSL_OP_TLSEXT_PADDING: c_ulong = 0x0;
 pub const SSL_OP_DONT_INSERT_EMPTY_FRAGMENTS: c_ulong = 0x00000800;
+#[cfg(not(any(libressl261, libressl262, libressl263)))]
 pub const SSL_OP_CRYPTOPRO_TLSEXT_BUG: c_ulong = 0x80000000;
+#[cfg(any(libressl261, libressl262, libressl263))]
+pub const SSL_OP_CRYPTOPRO_TLSEXT_BUG: c_ulong = 0x0;
 pub const SSL_OP_LEGACY_SERVER_CONNECT: c_ulong = 0x00000004;
 #[cfg(not(libressl))]
 pub const SSL_OP_SAFARI_ECDHE_ECDSA_BUG: c_ulong = 0x00000040;
