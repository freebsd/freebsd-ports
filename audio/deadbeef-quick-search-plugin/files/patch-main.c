--- main.c.orig	2016-01-02 12:26:07 UTC
+++ main.c
@@ -101,9 +101,17 @@ check_dir (const char *dir, mode_t mode)
 static int
 make_cache_dir (char *path, int size)
 {
+#if (DDB_API_LEVEL >= 8)
     const char *cache_dir = deadbeef->get_system_dir (DDB_SYS_DIR_CACHE);
+#else
+    const char *cache_dir = getenv ("HOME");
+#endif
     if (cache_dir) {
-        const int sz = snprintf (path, size, cache_dir ? "%s/quick_search/" : "%s/.cache/deadbeef/quick_search/", cache_dir ? cache_dir : getenv ("HOME"));
+#if (DDB_API_LEVEL >= 8)
+        const int sz = snprintf (path, size, "%s/quick_search/", cache_dir);
+#else
+        const int sz = snprintf (path, size, "%s/.cache/deadbeef/quick_search/", cache_dir);
+#endif
         if (!check_dir (path, 0755)) {
             return 0;
         }
@@ -432,14 +440,13 @@ on_searchentry_activate                (
         DB_playItem_t *it = deadbeef->plt_get_first (plt, PL_MAIN);
         while (it) {
             if (deadbeef->pl_is_selected (it)) {
+                int idx = deadbeef->plt_get_item_idx(plt, it, PL_MAIN);
+                deadbeef->sendmessage (DB_EV_PLAY_NUM, 0, idx, 0);
                 break;
             }
             DB_playItem_t *next = deadbeef->pl_get_next (it, PL_MAIN);
             deadbeef->pl_item_unref (it);
             it = next;
-            if (!it) {
-                deadbeef->sendmessage (DB_EV_PLAY_NUM, 0, 0, 0);
-            }
         }
         if (it) {
             deadbeef->pl_item_unref (it);
@@ -541,9 +548,9 @@ on_searchentry_key_press_event          
                                         gpointer         user_data)
 {
 #if GTK_CHECK_VERSION(3,0,0)
-    if (event->keyval == GDK_KEY_Return) {
+    if (event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_KP_Enter) {
 #else
-    if (event->keyval == GDK_Return) {
+    if (event->keyval == GDK_Return || event->keyval == GDK_KP_Enter) {
 #endif
         if (!config_autosearch) {
             GtkEntry *entry = GTK_ENTRY (widget);
@@ -1010,7 +1017,7 @@ quick_search_disconnect (void)
 // define plugin interface
 static DB_misc_t plugin = {
     .plugin.api_vmajor = 1,
-    .plugin.api_vminor = 8,
+    .plugin.api_vminor = 5,
     .plugin.version_major = 0,
     .plugin.version_minor = 1,
 #if GTK_CHECK_VERSION(3,0,0)
