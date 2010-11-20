--- src/gtkitementry_2_2.c.orig	2010-10-29 19:10:42.000000000 +0200
+++ src/gtkitementry_2_2.c	2010-10-29 19:11:29.000000000 +0200
@@ -156,7 +156,7 @@ static void         gtk_entry_draw_curso
 static PangoLayout *gtk_entry_ensure_layout            (GtkEntry       *entry,
                                                         gboolean        include_preedit);
 static void         gtk_entry_queue_draw               (GtkEntry       *entry);
-static void         gtk_entry_reset_im_context         (GtkEntry       *entry);
+//static void         gtk_entry_reset_im_context         (GtkEntry       *entry);
 static void         gtk_entry_recompute                (GtkEntry       *entry);
 static void         gtk_entry_get_cursor_locations     (GtkEntry       *entry,
 							CursorType      type,
@@ -1830,16 +1830,6 @@ gtk_entry_queue_draw (GtkEntry *entry)
 }
 
 static void
-gtk_entry_reset_im_context (GtkEntry *entry)
-{
-  if (entry->need_im_reset)
-    {
-      entry->need_im_reset = 0;
-      gtk_im_context_reset (entry->im_context);
-    }
-}
-
-static void
 gtk_entry_get_cursor_locations (GtkEntry   *entry,
 				CursorType  type,
 				gint       *strong_x,
