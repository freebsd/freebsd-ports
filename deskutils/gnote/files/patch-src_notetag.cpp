--- src/notetag.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/notetag.cpp
@@ -523,7 +523,7 @@ namespace gnote {
 
   bool NoteTagTable::tag_has_depth(const Glib::RefPtr<Gtk::TextBuffer::Tag> & tag)
   {
-    return DepthNoteTag::Ptr::cast_dynamic(tag);
+    return (bool)DepthNoteTag::Ptr::cast_dynamic(tag);
   }
 
 
