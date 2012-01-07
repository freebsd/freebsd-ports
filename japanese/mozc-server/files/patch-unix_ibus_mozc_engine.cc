--- unix/ibus/mozc_engine.cc.orig	2011-12-24 13:17:12.915092360 +0900
+++ unix/ibus/mozc_engine.cc	2012-01-07 13:40:28.811283808 +0900
@@ -1187,7 +1187,7 @@
 
       string selection_text;
       const uint32 selection_start = min(cursor_pos, anchor_pos);
-      const uint32 selection_length = abs(cursor_pos - anchor_pos);
+      const uint32 selection_length = ::abs(cursor_pos - anchor_pos);
       Util::SubString(surrounding_text,
                       selection_start,
                       selection_length,
