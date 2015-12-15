http://subversion.apache.org/security/CVE-2015-5343-advisory.txt
================================================================
--- subversion/mod_dav_svn/util.c.orig	2013-11-14 21:11:33 UTC
+++ subversion/mod_dav_svn/util.c
@@ -753,7 +753,12 @@ request_body_to_string(svn_string_t **re
 
   if (content_length)
     {
-      buf = svn_stringbuf_create_ensure(content_length, pool);
+      /* Do not allocate more than 1 MB until we receive request body. */
+      apr_size_t alloc_len = 1 * 1024 *1024;
+      if (content_length < alloc_len)
+        alloc_len = (apr_size_t) content_length;
+
+      buf = svn_stringbuf_create_ensure(alloc_len, pool);
     }
   else
     {
