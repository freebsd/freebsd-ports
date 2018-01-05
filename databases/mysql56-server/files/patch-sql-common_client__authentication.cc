sql-common/client_authentication.cc:87:56: error: comparison between pointer and integer ('char *' and 'int')
      mysql->options.extension->server_public_key_path != '\0')
      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ^  ~~~~

Part of https://github.com/mysql/mysql-server/commit/db1bde79b1b4

--- sql-common/client_authentication.cc.orig	2017-09-13 15:49:17 UTC
+++ sql-common/client_authentication.cc
@@ -84,7 +84,7 @@ RSA *rsa_init(MYSQL *mysql)
 
   if (mysql->options.extension != NULL &&
       mysql->options.extension->server_public_key_path != NULL &&
-      mysql->options.extension->server_public_key_path != '\0')
+      mysql->options.extension->server_public_key_path[0] != '\0')
   {
     pub_key_file= fopen(mysql->options.extension->server_public_key_path,
                         "r");
