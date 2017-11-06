--- src/notebuffer.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/notebuffer.cpp
@@ -248,7 +248,7 @@ namespace gnote {
 
     Glib::RefPtr<Gtk::TextTag> depth = find_depth_tag(iter);
 
-    return depth;
+    return (bool)depth;
   }
 
 
@@ -1341,7 +1341,7 @@ namespace gnote {
       if (iter.get_line() < buffer->get_line_count() - 1) {
         Gtk::TextIter next_line = buffer->get_iter_at_line(iter.get_line()+1);
         next_line_has_depth =
-          NoteBuffer::Ptr::cast_static(buffer)->find_depth_tag (next_line);
+          (bool)NoteBuffer::Ptr::cast_static(buffer)->find_depth_tag (next_line);
       }
 
       bool at_empty_line = iter.ends_line () && iter.starts_line ();
@@ -1576,7 +1576,7 @@ namespace gnote {
               NoteBuffer::Ptr note_buffer = NoteBuffer::Ptr::cast_dynamic(buffer);
               // Do not insert bullet if it's already there
               // this happens when using double identation in bullet list
-              if(note_buffer->find_depth_tag(apply_start) == 0) {
+              if(!note_buffer->find_depth_tag(apply_start)) {
                 note_buffer->insert_bullet (apply_start, depth_tag->get_depth(), depth_tag->get_direction());
                 buffer->remove_all_tags (apply_start, apply_start);
                 offset += 2;
