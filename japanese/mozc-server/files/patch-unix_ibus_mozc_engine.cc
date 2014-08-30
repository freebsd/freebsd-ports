--- unix/ibus/mozc_engine.cc.orig	2014-08-31 03:35:19.000000000 +0900
+++ unix/ibus/mozc_engine.cc	2014-08-31 04:04:15.000000000 +0900
@@ -224,7 +224,7 @@
   }
 
   const size_t selection_start = min(cursor_pos, anchor_pos);
-  const size_t selection_length = abs(info->relative_selected_length);
+  const size_t selection_length = ::abs(info->relative_selected_length);
   Util::SubStringPiece(surrounding_text, 0, selection_start)
       .CopyToString(&info->preceding_text);
   Util::SubStringPiece(surrounding_text, selection_start, selection_length)
