--- unix/ibus/mozc_engine.cc.orig	2012-09-07 10:21:29.111022215 +0900
+++ unix/ibus/mozc_engine.cc	2012-09-07 10:30:26.452021649 +0900
@@ -756,7 +756,7 @@
       //     on size_t, not uint32.
       string selection_text;
       const uint32 selection_start = min(cursor_pos, anchor_pos);
-      const uint32 selection_length = abs(relative_selected_length);
+      const uint32 selection_length = ::abs(relative_selected_length);
       Util::SubString(surrounding_text,
                       selection_start,
                       selection_length,
