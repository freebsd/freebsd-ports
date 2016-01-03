--- zathura/main.c.orig	2015-12-21 10:19:18 UTC
+++ zathura/main.c
@@ -85,10 +85,13 @@ run_synctex_forward(const char* synctex_
 static zathura_t*
 init_zathura(const char* config_dir, const char* data_dir,
     const char* cache_dir, const char* plugin_path, char** argv,
+#ifdef WITH_SYNCTEX
+    char* synctex_editor,
+#endif
 #ifdef GDK_WINDOWING_X11
-    char* synctex_editor, Window embed)
+    Window embed)
 #else
-    char* synctex_editor)
+    )
 #endif
 {
   /* create zathura session */
@@ -249,11 +252,14 @@ main(int argc, char* argv[])
   gtk_init(&argc, &argv);
 
   /* Create zathura session */
-  zathura_t* zathura = init_zathura(config_dir, data_dir, cache_dir,
+  zathura_t* zathura = init_zathura(config_dir, data_dir, cache_dir, plugin_path, argv,
+#ifdef WITH_SYNCTEX
+      synctex_editor,
+#endif
 #ifdef GDK_WINDOWING_X11
-      plugin_path, argv, synctex_editor, embed);
+      embed);
 #else
-      plugin_path, argv, synctex_editor);
+      );
 #endif
   if (zathura == NULL) {
     girara_error("Could not initialize zathura.");
