--- src/cong-editor-node-element-span.c.orig	Tue Feb 17 18:24:28 2004
+++ src/cong-editor-node-element-span.c	Wed Feb 18 09:58:02 2004
@@ -145,9 +145,9 @@
 				
 				if (child_line_fragments) {
 					GList* list_of_areas;
-					list_of_areas = cong_editor_line_fragments_get_area_list (child_line_fragments);
-					
 					gboolean is_first = TRUE;
+					
+					list_of_areas = cong_editor_line_fragments_get_area_list (child_line_fragments);
 					
 					while (list_of_areas) {
 						
