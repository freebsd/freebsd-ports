--- unix/ibus/mozc_engine.cc.orig	2012-05-29 15:36:59.665961241 +0900
+++ unix/ibus/mozc_engine.cc	2012-05-01 12:45:44.250693013 +0900
@@ -893,7 +893,7 @@
       //     on size_t, not uint32.
       string selection_text;
       const uint32 selection_start = min(cursor_pos, anchor_pos);
-      const uint32 selection_length = abs(relative_selected_length);
+      const uint32 selection_length = ::abs(relative_selected_length);
       Util::SubString(surrounding_text,
                       selection_start,
                       selection_length,
