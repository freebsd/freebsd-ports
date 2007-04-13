--- src/baz/libarch/pfs-sftp.c.orig	Mon Jun 20 23:59:37 2005
+++ src/baz/libarch/pfs-sftp.c	Thu Apr  5 09:16:19 2007
@@ -1496,7 +1496,7 @@
    */
   arch_uri_heuristics (&parsed_uri);
 
-  *user = str_save (0, parsed_uri.authinfo);
+  *user = str_save (0, parsed_uri.userinfo);
   *hostname = str_save (0, parsed_uri.host);
   if (parsed_uri.port)
     {
