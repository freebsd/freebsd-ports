--- src/gtkitementry.c.orig	2010-10-31 15:58:33.000000000 +0100
+++ src/gtkitementry.c	2010-10-31 15:59:28.000000000 +0100
@@ -131,7 +131,7 @@ static void         gtk_entry_draw_curso
 static PangoLayout *gtk_entry_ensure_layout            (GtkEntry       *entry,
                                                         gboolean        include_preedit);
 static void         gtk_entry_queue_draw               (GtkEntry       *entry);
-static void         gtk_entry_reset_im_context         (GtkEntry       *entry);
+static void         nip_gtk_entry_reset_im_context         (GtkEntry       *entry);
 static void         gtk_entry_recompute                (GtkEntry       *entry);
 static void         gtk_entry_get_cursor_locations     (GtkEntry       *entry,
 							CursorType      type,
@@ -657,7 +657,7 @@ gtk_entry_real_set_position (GtkEditable
   if (position != entry->current_pos ||
       position != entry->selection_bound)
     {
-      gtk_entry_reset_im_context (entry);
+      nip_gtk_entry_reset_im_context (entry);
       gtk_entry_set_positions (entry, position, position);
     }
 }
@@ -823,7 +823,7 @@ gtk_entry_move_cursor (GtkEntry       *e
 {
   gint new_pos = entry->current_pos;
 
-  gtk_entry_reset_im_context (entry);
+  nip_gtk_entry_reset_im_context (entry);
 
   if (entry->current_pos != entry->selection_bound && !extend_selection)
     {
@@ -917,7 +917,7 @@ gtk_entry_insert_at_cursor (GtkEntry    
 
   if (entry->editable)
     {
-      gtk_entry_reset_im_context (entry);
+      nip_gtk_entry_reset_im_context (entry);
 
       gtk_editable_insert_text (editable, str, -1, &pos);
       gtk_editable_set_position (editable, pos);
@@ -933,7 +933,7 @@ gtk_entry_delete_from_cursor (GtkEntry  
   gint start_pos = entry->current_pos;
   gint end_pos = entry->current_pos;
   
-  gtk_entry_reset_im_context (entry);
+  nip_gtk_entry_reset_im_context (entry);
 
   if (!entry->editable)
     return;
@@ -1699,7 +1699,7 @@ gtk_entry_queue_draw (GtkEntry *entry)
 }
 
 static void
-gtk_entry_reset_im_context (GtkEntry *entry)
+nip_gtk_entry_reset_im_context (GtkEntry *entry)
 {
   if (entry->need_im_reset)
     {
