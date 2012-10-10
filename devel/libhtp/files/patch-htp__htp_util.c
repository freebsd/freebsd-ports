--- ./htp/htp_util.c.orig	2012-10-09 18:53:48.000000000 -0400
+++ ./htp/htp_util.c	2012-10-09 18:54:31.000000000 -0400
@@ -2099,7 +2099,8 @@
         len += bstr_len(hl->line);
     }
 
-    len += bstr_len(tx->request_headers_sep);
+    if (tx->request_headers_sep)
+        len += bstr_len(tx->request_headers_sep);
 
     request_headers_raw = bstr_alloc(len);
     if (request_headers_raw == NULL) {
@@ -2112,7 +2113,8 @@
         bstr_add_noex(request_headers_raw, hl->line);
     }
 
-    bstr_add_noex(request_headers_raw, tx->request_headers_sep);
+    if (tx->request_headers_sep)
+        bstr_add_noex(request_headers_raw, tx->request_headers_sep);
 
     return request_headers_raw;
 }
