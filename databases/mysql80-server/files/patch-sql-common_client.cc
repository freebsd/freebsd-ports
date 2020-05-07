--- sql-common/client.cc.orig	2020-03-26 13:31:45 UTC
+++ sql-common/client.cc
@@ -7752,6 +7752,7 @@ int STDCALL mysql_options(MYSQL *mysql, enum mysql_opt
         return 1;
       break;
     case MYSQL_OPT_SSL_FIPS_MODE: {
+#if !defined(LIBRESSL_VERSION_NUMBER)
       char ssl_err_string[OPENSSL_ERROR_LENGTH] = {'\0'};
       ENSURE_EXTENSIONS_PRESENT(&mysql->options);
       mysql->options.extension->ssl_fips_mode = *static_cast<const uint *>(arg);
@@ -7763,6 +7764,7 @@ int STDCALL mysql_options(MYSQL *mysql, enum mysql_opt
             "Set Fips mode ON/STRICT failed, detail: '%s'.", ssl_err_string);
         return 1;
       }
+#endif
     } break;
     case MYSQL_OPT_SSL_MODE:
       ENSURE_EXTENSIONS_PRESENT(&mysql->options);
