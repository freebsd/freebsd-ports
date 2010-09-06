--- src/retr.c	2010-05-08 19:56:15 +0000
+++ src/retr.c	2010-07-28 19:22:22 +0000
@@ -731,7 +731,8 @@
 #endif
       || (proxy_url && proxy_url->scheme == SCHEME_HTTP))
     {
-      result = http_loop (u, &mynewloc, &local_file, refurl, dt, proxy_url, iri);
+      result = http_loop (u, orig_parsed, &mynewloc, &local_file, refurl, dt,
+                          proxy_url, iri);
     }
   else if (u->scheme == SCHEME_FTP)
     {

