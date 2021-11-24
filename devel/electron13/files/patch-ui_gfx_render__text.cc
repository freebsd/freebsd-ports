--- ui/gfx/render_text.cc.orig	2021-07-15 19:14:08 UTC
+++ ui/gfx/render_text.cc
@@ -1203,23 +1203,24 @@ void RenderText::SetDisplayOffset(Vector2d offset) {
   const int extra_content = GetContentWidth() - display_rect_.width();
   const int cursor_width = cursor_enabled_ ? 1 : 0;
 
-  int min_offset = 0;
-  int max_offset = 0;
+  // avoid collisions with vm_map.h on FreeBSD --cmt
+  int _min_offset = 0;
+  int _max_offset = 0;
   if (extra_content > 0) {
     switch (GetCurrentHorizontalAlignment()) {
       case ALIGN_LEFT:
-        min_offset = -extra_content;
+        _min_offset = -extra_content;
         break;
       case ALIGN_RIGHT:
-        max_offset = extra_content;
+        _max_offset = extra_content;
         break;
       case ALIGN_CENTER:
         // The extra space reserved for cursor at the end of the text is ignored
         // when centering text. So, to calculate the valid range for offset, we
         // exclude that extra space, calculate the range, and add it back to the
         // range (if cursor is enabled).
-        min_offset = -(extra_content - cursor_width + 1) / 2 - cursor_width;
-        max_offset = (extra_content - cursor_width) / 2;
+        _min_offset = -(extra_content - cursor_width + 1) / 2 - cursor_width;
+        _max_offset = (extra_content - cursor_width) / 2;
         break;
       default:
         break;
@@ -1227,7 +1228,7 @@ void RenderText::SetDisplayOffset(Vector2d offset) {
   }
 
   const int horizontal_offset =
-      base::ClampToRange(offset.x(), min_offset, max_offset);
+      base::ClampToRange(offset.x(), _min_offset, _max_offset);
 
   // y-offset is set only when the vertical alignment is ALIGN_TOP.
   // TODO(jongkown.lee): Support other vertical alignments.
