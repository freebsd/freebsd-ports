sql-common/client_authentication.cc:86:56: error: comparison between pointer and integer ('char *' and 'int')
      mysql->options.extension->server_public_key_path != '\0')
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^  ~~~~

--- sql-common/client_authentication.cc.orig	2018-08-27 19:39:51 UTC
+++ sql-common/client_authentication.cc
@@ -83,7 +83,7 @@ RSA *rsa_init(MYSQL *mysql)
 
   if (mysql->options.extension != NULL &&
       mysql->options.extension->server_public_key_path != NULL &&
-      mysql->options.extension->server_public_key_path != '\0')
+      *mysql->options.extension->server_public_key_path != '\0')
   {
     pub_key_file= fopen(mysql->options.extension->server_public_key_path,
                         "r");
