

===================================================================
--- ./subversion/libsvn_ra_dav/.svn/text-base/session.c	Wed Oct 17 11:34:54 2001
+++ ./subversion/libsvn_ra_dav/session.c	Wed Oct 17 15:30:15 2001
@@ -103,6 +103,7 @@
   ne_session *sess, *sess2;
   struct uri uri = { 0 };
   svn_ra_session_t *ras;
+  char *proxy;
 
   /* Sanity check the URI */
   if (uri_parse(repository, &uri, NULL) 
@@ -121,6 +122,26 @@
   /* Create two neon session objects, and set their properties... */
   sess = ne_session_create();
   sess2 = ne_session_create();
+
+  /* Proxy setup must be done early */
+  proxy = getenv("http_proxy");
+  if (proxy != NULL)
+    {
+      struct uri proxy_uri = { 0 };
+      struct uri proxy_uri_default = { port: 80 };
+      if (uri_parse(proxy, &proxy_uri, &proxy_uri_default)
+          || uri.host == NULL)
+        {
+          return svn_error_create(SVN_ERR_RA_ILLEGAL_URL, 0, NULL, pool,
+                                  "illegal URL for proxy");
+        }
+      if (ne_session_proxy(sess, proxy_uri.host, proxy_uri.port)
+         || ne_session_proxy(sess2, proxy_uri.host, proxy_uri.port))
+        {
+          return svn_error_createf(SVN_ERR_RA_HOSTNAME_LOOKUP, 0, NULL, pool,
+                                  "Hostname not found: %s", proxy_uri.host);
+        }
+    }
 
 #if 0
   /* #### enable this block for debugging output on stderr. */

---------------------------------------------------------------------
To unsubscribe, e-mail: dev-unsubscribe@subversion.tigris.org
For additional commands, e-mail: dev-help@subversion.tigris.org


