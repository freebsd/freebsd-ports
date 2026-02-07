--- src/PrimitiveFunction.cc.orig	2019-06-23 12:39:20 UTC
+++ src/PrimitiveFunction.cc
@@ -2668,8 +2668,8 @@ Value_P Z(ShapeItem(line_starts.size() - 1), LOC);
         else
            len = result_utf8.size() - line_starts[l];
 
-        UTF8_string line_utf8(&result_utf8[line_starts[l]], len);
-        UCS_string line_ucs(line_utf8);
+        const UTF8_string line_utf8(utf8P(&result_utf8[line_starts[l]]), len);
+        const UCS_string line_ucs(line_utf8);
         Value_P ZZ(line_ucs, LOC);
         new (Z->next_ravel())   PointerCell(ZZ.get(), Z.getref());
       }
