--- subversion/mod_dav_svn/mod_dav_svn.c	2011/08/19 17:13:38	1159686
+++ subversion/mod_dav_svn/mod_dav_svn.c	2011/10/22 11:32:38	1187695
@@ -902,13 +902,17 @@
 /* Response handler for POST requests (protocol-v2 commits).  */
 static int dav_svn__handler(request_rec *r)
 {
-  /* HTTP-defined Methods we handle */
-  r->allowed = 0
-    | (AP_METHOD_BIT << M_POST);
-
-  if (r->method_number == M_POST) {
-    return dav_svn__method_post(r);
-  }
+  dir_conf_t *conf = ap_get_module_config(r->per_dir_config, &dav_svn_module);
+
+  if (conf->fs_path || conf->fs_parent_path)
+    {
+      /* HTTP-defined Methods we handle */
+      r->allowed = 0
+        | (AP_METHOD_BIT << M_POST);
+
+      if (r->method_number == M_POST)
+        return dav_svn__method_post(r);
+    }
 
   return DECLINED;
 }
