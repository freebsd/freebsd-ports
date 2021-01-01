--- ui/gfx/render_text.cc.orig	2019-12-12 12:41:33 UTC
+++ ui/gfx/render_text.cc
@@ -983,32 +983,33 @@ void RenderText::SetDisplayOffset(int horizontal_offse
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
     }
   }
-  if (horizontal_offset < min_offset)
-    horizontal_offset = min_offset;
-  else if (horizontal_offset > max_offset)
-    horizontal_offset = max_offset;
+  if (horizontal_offset < _min_offset)
+    horizontal_offset = _min_offset;
+  else if (horizontal_offset > _max_offset)
+    horizontal_offset = _max_offset;
 
   cached_bounds_and_offset_valid_ = true;
   display_offset_.set_x(horizontal_offset);
