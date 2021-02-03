--- sql/ssl_init_callback.cc.orig	2020-12-11 07:42:20 UTC
+++ sql/ssl_init_callback.cc
@@ -88,7 +88,7 @@ static Sys_var_charptr Sys_tls_version(
     "TLS version, permitted values are TLSv1, TLSv1.1, TLSv1.2, TLSv1.3",
     PERSIST_AS_READONLY GLOBAL_VAR(opt_tls_version),
     CMD_LINE(REQUIRED_ARG, OPT_TLS_VERSION), IN_FS_CHARSET,
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
     "TLSv1,TLSv1.1,TLSv1.2,TLSv1.3",
 #else
     "TLSv1,TLSv1.1,TLSv1.2",
@@ -154,7 +154,7 @@ static Sys_var_charptr Sys_admin_tls_version(
     "TLSv1.2, TLSv1.3",
     PERSIST_AS_READONLY GLOBAL_VAR(opt_admin_tls_version),
     CMD_LINE(REQUIRED_ARG, OPT_TLS_VERSION), IN_FS_CHARSET,
-#ifdef HAVE_TLSv13
+#if defined(HAVE_TLSv13) && !defined(LIBRESSL_VERSION_NUMBER)
     "TLSv1,TLSv1.1,TLSv1.2,TLSv1.3",
 #else
     "TLSv1,TLSv1.1,TLSv1.2",
