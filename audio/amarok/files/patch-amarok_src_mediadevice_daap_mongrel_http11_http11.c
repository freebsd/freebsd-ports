--- ./amarok/src/mediadevice/daap/mongrel/http11/http11.c.orig	2011-08-27 14:56:26.000000000 +0000
+++ ./amarok/src/mediadevice/daap/mongrel/http11/http11.c	2011-08-27 14:58:15.000000000 +0000
@@ -74,7 +74,7 @@
   f = rb_str_dup(global_http_prefix);
   f = rb_str_buf_cat(f, field, flen); 
 
-  for(ch = RSTRING(f)->ptr, end = ch + RSTRING(f)->len; ch < end; ch++) {
+  for(ch = RSTRING_PTR(f), end = ch + RSTRING_LEN(f); ch < end; ch++) {
     if(*ch == '-') {
       *ch = '_';
     } else {
@@ -157,12 +157,12 @@
 
   rb_hash_aset(req, global_gateway_interface, global_gateway_interface_value);
   if((temp = rb_hash_aref(req, global_http_host)) != Qnil) {
-    colon = strchr(RSTRING(temp)->ptr, ':');
+    colon = strchr(RSTRING_PTR(temp), ':');
     if(colon != NULL) {
-      rb_hash_aset(req, global_server_name, rb_str_substr(temp, 0, colon - RSTRING(temp)->ptr));
+      rb_hash_aset(req, global_server_name, rb_str_substr(temp, 0, colon - RSTRING_PTR(temp)));
       rb_hash_aset(req, global_server_port, 
-          rb_str_substr(temp, colon - RSTRING(temp)->ptr+1, 
-            RSTRING(temp)->len));
+          rb_str_substr(temp, colon - RSTRING_PTR(temp)+1, 
+            RSTRING_LEN(temp)));
     } else {
       rb_hash_aset(req, global_server_name, temp);
       rb_hash_aset(req, global_server_port, global_port_80);
@@ -281,8 +281,8 @@
   DATA_GET(self, http_parser, http);
 
   from = FIX2INT(start);
-  dptr = RSTRING(data)->ptr;
-  dlen = RSTRING(data)->len;
+  dptr = RSTRING_PTR(data);
+  dlen = RSTRING_LEN(data);
 
   if(from >= dlen) {
     rb_raise(eHttpParserError, "Requested start is after data buffer end.");
@@ -512,7 +512,7 @@
     if(pref_len == 1 && uri_str[0] == '/') {
       rb_ary_push(result, uri);
     } else {
-      rb_ary_push(result, rb_str_substr(uri, pref_len, RSTRING(uri)->len));
+      rb_ary_push(result, rb_str_substr(uri, pref_len, RSTRING_LEN(uri)));
     }
 
     rb_ary_push(result, (VALUE)handler);
