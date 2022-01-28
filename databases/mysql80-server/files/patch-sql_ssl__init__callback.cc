--- sql/ssl_init_callback.cc.orig	2021-12-17 16:07:27 UTC
+++ sql/ssl_init_callback.cc
@@ -106,14 +106,14 @@ static Sys_var_charptr Sys_ssl_capath(
 
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
@@ -175,14 +175,14 @@ static Sys_var_charptr Sys_admin_ssl_capath(
 
 static Sys_var_charptr Sys_admin_tls_version(
     "admin_tls_version",
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
     "TLS version for --admin-port, permitted values are TLSv1.2, TLSv1.3",
 #else
     "TLS version for --admin-port, permitted values are TLSv1.2",
 #endif
     PERSIST_AS_READONLY GLOBAL_VAR(opt_admin_tls_version),
     CMD_LINE(REQUIRED_ARG, OPT_TLS_VERSION), IN_FS_CHARSET,
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
     "TLSv1.2,TLSv1.3",
 #else
     "TLSv1.2",
