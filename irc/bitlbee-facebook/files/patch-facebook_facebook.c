--- facebook/facebook.c.orig	2016-01-16 15:20:59 UTC
+++ facebook/facebook.c
@@ -1082,3 +1082,24 @@ init_plugin(void)
     root_command_add("fbcreate", 0, fb_cmd_fbcreate, 0);
     root_command_add("fbjoin", 0, fb_cmd_fbjoin, 0);
 }
+
+
+#ifdef BITLBEE_ABI_VERSION_CODE
+G_MODULE_EXPORT struct plugin_info *
+init_plugin_info(void);
+
+G_MODULE_EXPORT struct plugin_info *
+init_plugin_info(void)
+{
+    static struct plugin_info info = {
+        BITLBEE_ABI_VERSION_CODE,
+        "facebook",
+        PACKAGE_VERSION,
+        "Facebook protocol plugin",
+        "dequis <dx@dxzone.com.ar> (maintainer), James Geboski <jgeboski@gmail.com> (original author)",
+        PACKAGE_URL
+    };
+
+    return &info;
+}
+#endif /* BITLBEE_ABI_VERSION_CODE */
