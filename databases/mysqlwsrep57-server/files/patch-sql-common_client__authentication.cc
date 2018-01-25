--- sql-common/client_authentication.cc.orig	2018-01-22 16:19:07.776289000 +0200
+++ sql-common/client_authentication.cc	2018-01-22 16:19:26.756981000 +0200
@@ -84,7 +84,7 @@
 
   if (mysql->options.extension != NULL &&
       mysql->options.extension->server_public_key_path != NULL &&
-      mysql->options.extension->server_public_key_path != '\0')
+      mysql->options.extension->server_public_key_path[0] != '\0')
   {
     pub_key_file= fopen(mysql->options.extension->server_public_key_path,
                         "r");
