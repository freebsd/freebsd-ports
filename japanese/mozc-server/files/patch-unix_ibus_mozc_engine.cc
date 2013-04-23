--- unix/ibus/mozc_engine.cc.orig	2013-04-21 03:48:44.433270458 +0900
+++ unix/ibus/mozc_engine.cc	2013-04-21 04:12:50.609270610 +0900
@@ -758,7 +758,7 @@
       //     on size_t, not uint32.
       string selection_text;
       const uint32 selection_start = min(cursor_pos, anchor_pos);
-      const uint32 selection_length = abs(relative_selected_length);
+      const uint32 selection_length = ::abs(relative_selected_length);
       Util::SubString(surrounding_text,
                       selection_start,
                       selection_length,
