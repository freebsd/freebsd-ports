--- sql-common/client.cc.orig	2021-12-17 16:07:27 UTC
+++ sql-common/client.cc
@@ -8301,6 +8301,7 @@ int STDCALL mysql_options(MYSQL *mysql, enum mysql_opt
         return 1;
       break;
     case MYSQL_OPT_SSL_FIPS_MODE: {
+#if !defined(LIBRESSL_VERSION_NUMBER)
       char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
       ENSURE_EXTENSIONS_PRESENT(&mysql->options);
       mysql->options.extension->ssl_fips_mode =
@@ -8313,6 +8314,7 @@ int STDCALL mysql_options(MYSQL *mysql, enum mysql_opt
             "Set Fips mode ON/STRICT failed, detail: '%s'.", ssl_err_string);
         return 1;
       }
+#endif
     } break;
     case MYSQL_OPT_SSL_MODE:
       ENSURE_EXTENSIONS_PRESENT(&mysql->options);
