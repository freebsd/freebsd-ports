--- sql/ssl_init_callback.cc.orig	2024-04-10 06:26:28 UTC
+++ sql/ssl_init_callback.cc
@@ -165,14 +165,14 @@ static Sys_var_charptr Sys_tls_version(
 
 static Sys_var_charptr Sys_tls_version(
     "tls_version",
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
     "TLS version, permitted values are TLSv1.2, TLSv1.3",
 #else
     "TLS version, permitted values are TLSv1.2",
 #endif
     PERSIST_AS_READONLY GLOBAL_VAR(opt_tls_version),
     CMD_LINE(REQUIRED_ARG, OPT_TLS_VERSION), IN_FS_CHARSET,
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
     "TLSv1.2,TLSv1.3",
 #else
     "TLSv1.2",
@@ -248,14 +248,14 @@ static Sys_var_charptr Sys_admin_tls_version(
 
 static Sys_var_charptr Sys_admin_tls_version(
     "admin_tls_version",
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
     "TLS version for --admin-port, permitted values are TLSv1.2, TLSv1.3",
 #else
     "TLS version for --admin-port, permitted values are TLSv1.2",
 #endif
     PERSIST_AS_READONLY GLOBAL_VAR(opt_admin_tls_version),
     CMD_LINE(REQUIRED_ARG, OPT_ADMIN_TLS_VERSION), IN_FS_CHARSET,
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
     "TLSv1.2,TLSv1.3",
 #else
     "TLSv1.2",
