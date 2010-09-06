--- src/http.c	2010-07-20 17:42:13 +0000
+++ src/http.c	2010-07-28 19:22:22 +0000
@@ -2593,8 +2593,9 @@
 /* The genuine HTTP loop!  This is the part where the retrieval is
    retried, and retried, and retried, and...  */
 uerr_t
-http_loop (struct url *u, char **newloc, char **local_file, const char *referer,
-           int *dt, struct url *proxy, struct iri *iri)
+http_loop (struct url *u, struct url *original_url, char **newloc,
+           char **local_file, const char *referer, int *dt, struct url *proxy,
+           struct iri *iri)
 {
   int count;
   bool got_head = false;         /* used for time-stamping and filename detection */
@@ -2641,7 +2642,8 @@
     }
   else if (!opt.content_disposition)
     {
-      hstat.local_file = url_file_name (u);
+      hstat.local_file =
+        url_file_name (opt.trustservernames ? u : original_url);
       got_name = true;
     }
 
@@ -2679,7 +2681,7 @@
 
   /* Send preliminary HEAD request if -N is given and we have an existing
    * destination file. */
-  file_name = url_file_name (u);
+  file_name = url_file_name (opt.trustservernames ? u : original_url);
   if (opt.timestamping
       && !opt.content_disposition
       && file_exists_p (file_name))
