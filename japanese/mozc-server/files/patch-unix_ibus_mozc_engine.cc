--- unix/ibus/mozc_engine.cc.orig	2013-07-17 11:37:50.000000000 +0900
+++ unix/ibus/mozc_engine.cc	2013-07-19 22:37:55.000000000 +0900
@@ -265,7 +265,7 @@
   }
 
   const uint32 selection_start = min(cursor_pos, anchor_pos);
-  const uint32 selection_length = abs(info->relative_selected_length);
+  const uint32 selection_length = ::abs(info->relative_selected_length);
   info->preceding_text = surrounding_text.substr(0, selection_start);
   Util::SubString(surrounding_text,
                   selection_start,
