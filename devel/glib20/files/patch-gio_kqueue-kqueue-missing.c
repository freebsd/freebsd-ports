--- gio/kqueue/kqueue-missing.c.orig	2018-04-09 22:48:45.637366000 +0200
+++ gio/kqueue/kqueue-missing.c	2018-04-09 22:48:55.840341000 +0200
@@ -23,12 +23,12 @@
 #include <glib.h>
 
 #include "kqueue-helper.h"
-#include "kqueue-sub.h"
-#include "kqueue-missing.h"
 
 
 #define SCAN_MISSING_TIME 4 /* 1/4 Hz */
 
+void _kh_file_appeared_cb (kqueue_sub *sub);
+
 static gboolean km_scan_missing (gpointer user_data);
 
 static gboolean km_debug_enabled = FALSE;
@@ -38,24 +38,9 @@ static GSList *missing_subs_list = NULL;
 G_LOCK_DEFINE_STATIC (missing_lock);
 
 static volatile gboolean scan_missing_running = FALSE;
-static on_create_cb file_appeared_callback;
 
 
 /**
- * _km_init:
- * @cb: a callback function. It will be called when a watched file
- *     will appear.
- *
- * Initialize the kqueue-missing module (optional).
- **/
-void
-_km_init (on_create_cb cb)
-{
-  file_appeared_callback = cb;
-}
-
-
-/**
  * _km_add_missing:
  * @sub: a #kqueue_sub
  *
@@ -83,7 +68,36 @@ _km_add_missing (kqueue_sub *sub)
     }
 }
 
+/**
+ * _kh_file_appeared_cb:
+ * @sub: a #kqueue_sub
+ *
+ * A callback function for kqueue-missing subsystem.
+ *
+ * Signals that a missing file has finally appeared in the filesystem.
+ * Emits %G_FILE_MONITOR_EVENT_CREATED.
+ **/
+void
+_kh_file_appeared_cb (kqueue_sub *sub)
+{
+  GFile *child;
 
+  g_assert (sub != NULL);
+  g_assert (sub->filename);
+
+  if (!g_file_test (sub->filename, G_FILE_TEST_EXISTS))
+    return;
+
+  child = g_file_new_for_path (sub->filename);
+
+  g_file_monitor_emit_event (G_FILE_MONITOR (sub->mon),
+                             child,
+                             NULL,
+                             G_FILE_MONITOR_EVENT_CREATED);
+
+  g_object_unref (child);
+}
+
 /**
  * km_scan_missing:
  * @user_data: unused
@@ -114,11 +128,10 @@ km_scan_missing (gpointer user_data)
       g_assert (sub != NULL);
       g_assert (sub->filename != NULL);
 
-      if (_kh_start_watching (sub))
+      if (_kqsub_start_watching (sub))
         {
           KM_W ("file %s now exists, starting watching", sub->filename);
-          if (file_appeared_callback)
-            file_appeared_callback (sub);
+          _kh_file_appeared_cb (sub);
           not_missing = g_slist_prepend (not_missing, head);
         }
     }
