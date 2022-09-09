--- src/java.desktop/share/native/libharfbuzz/hb-ot-layout-gpos-table.hh.orig	2022-07-20 05:18:35 UTC
+++ src/java.desktop/share/native/libharfbuzz/hb-ot-layout-gpos-table.hh
@@ -1128,7 +1128,7 @@ struct PairSet
     if (record)
     {
       /* Note the intentional use of "|" instead of short-circuit "||". */
-      if (valueFormats[0].apply_value (c, this, &record->values[0], buffer->cur_pos()) |
+	    if ((int)valueFormats[0].apply_value (c, this, &record->values[0], buffer->cur_pos()) |
           valueFormats[1].apply_value (c, this, &record->values[len1], buffer->pos[pos]))
         buffer->unsafe_to_break (buffer->idx, pos + 1);
       if (len2)
@@ -1414,7 +1414,7 @@ struct PairPosFormat2
 
     const Value *v = &values[record_len * (klass1 * class2Count + klass2)];
     /* Note the intentional use of "|" instead of short-circuit "||". */
-    if (valueFormat1.apply_value (c, this, v, buffer->cur_pos()) |
+    if ((int)valueFormat1.apply_value (c, this, v, buffer->cur_pos()) |
         valueFormat2.apply_value (c, this, v + len1, buffer->pos[skippy_iter.idx]))
       buffer->unsafe_to_break (buffer->idx, skippy_iter.idx + 1);
 
