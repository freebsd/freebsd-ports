--- src/addins/printnotes/printnotesnoteaddin.cpp.orig	2015-11-28 15:44:34 UTC
+++ src/addins/printnotes/printnotesnoteaddin.cpp
@@ -277,7 +277,7 @@ namespace printnotes {
     }
 
     gnote::DepthNoteTag::Ptr depth = get_buffer()->find_depth_tag(p_start);
-    if(depth != 0) {
+    if(depth) {
         indentation += ((int) (dpiX / 3)) * depth->get_depth();
     }
     layout->set_width(pango_units_from_double((int)context->get_width() -
