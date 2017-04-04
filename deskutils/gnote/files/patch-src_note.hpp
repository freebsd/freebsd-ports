--- src/note.hpp.orig	2015-11-28 15:44:34 UTC
+++ src/note.hpp
@@ -124,7 +124,7 @@ public:
   const Glib::RefPtr<NoteTagTable> & get_tag_table();
   bool has_buffer() const
     {
-      return m_buffer;
+      return (bool)m_buffer;
     }
   const Glib::RefPtr<NoteBuffer> & get_buffer();
   bool has_window() const 
@@ -139,7 +139,7 @@ public:
   bool is_special() const;
   bool is_loaded() const
     {
-      return (m_buffer);
+      return (bool)m_buffer;
     }
   bool is_opened() const
     { 
