--- src/baz/libarch/tests/unit-sftp.c.orig	Mon Jun 20 23:59:37 2005
+++ src/baz/libarch/tests/unit-sftp.c	Thu Apr  5 09:58:45 2007
@@ -35,7 +35,7 @@
     char *host;
     unsigned int port;
     char *path;
-    char *authinfo;
+    char *userinfo;
 } ne_uri;
 */
   invariant_int_cmp (ne_uri_parse ("sftp://user@email.com@host.phwoar/root/path", &parsed_uri), 0);
@@ -44,7 +44,7 @@
   invariant_str_cmp (parsed_uri.host, "email.com@host.phwoar");
   arch_uri_heuristics (&parsed_uri);
   invariant_str_cmp (parsed_uri.host, "host.phwoar");
-  invariant_str_cmp (parsed_uri.authinfo, "user@email.com");
+  invariant_str_cmp (parsed_uri.userinfo, "user@email.com");
   invariant_int_cmp (parsed_uri.port, 0);
   ne_uri_free(&parsed_uri);
 
