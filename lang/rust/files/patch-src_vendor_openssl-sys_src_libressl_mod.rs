--- src/vendor/openssl-sys/src/libressl/mod.rs.orig	2017-10-09 21:52:49 UTC
+++ src/vendor/openssl-sys/src/libressl/mod.rs
@@ -345,6 +345,9 @@ pub const SSL_CTRL_OPTIONS: c_int = 32;
 pub const SSL_CTRL_CLEAR_OPTIONS: c_int = 77;
 pub const SSL_CTRL_SET_ECDH_AUTO: c_int = 94;
 
+#[cfg(any(libressl261, libressl262, libressl263))]
+pub const SSL_OP_ALL: c_ulong = 0x4;
+#[cfg(not(any(libressl261, libressl262, libressl263)))]
 pub const SSL_OP_ALL: c_ulong = 0x80000014;
 pub const SSL_OP_CISCO_ANYCONNECT: c_ulong = 0x0;
 pub const SSL_OP_NO_COMPRESSION: c_ulong = 0x0;
@@ -357,6 +360,9 @@ pub const SSL_OP_MICROSOFT_BIG_SSLV3_BUFFER: c_ulong =
 pub const SSL_OP_SSLEAY_080_CLIENT_DH_BUG: c_ulong = 0x0;
 pub const SSL_OP_TLS_D5_BUG: c_ulong = 0x0;
 pub const SSL_OP_TLS_BLOCK_PADDING_BUG: c_ulong = 0x0;
+#[cfg(any(libressl261, libressl262, libressl263))]
+pub const SSL_OP_SINGLE_ECDH_USE: c_ulong = 0x0;
+#[cfg(not(any(libressl261, libressl262, libressl263)))]
 pub const SSL_OP_SINGLE_ECDH_USE: c_ulong = 0x00080000;
 pub const SSL_OP_SINGLE_DH_USE: c_ulong = 0x00100000;
 pub const SSL_OP_NO_SSLv2: c_ulong = 0x0;
