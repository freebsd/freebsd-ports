--- unix/ibus/mozc_engine.cc.orig	2012-01-29 13:42:31.155805132 +0900
+++ unix/ibus/mozc_engine.cc	2012-01-29 13:49:15.880806284 +0900
@@ -1205,7 +1205,7 @@
 
       string selection_text;
       const uint32 selection_start = min(cursor_pos, anchor_pos);
-      const uint32 selection_length = abs(cursor_pos - anchor_pos);
+      const uint32 selection_length = ::abs(cursor_pos - anchor_pos);
       Util::SubString(surrounding_text,
                       selection_start,
                       selection_length,
