Index: byterun/major_gc.c
===================================================================
RCS file: /net/pauillac/caml/repository/csl/byterun/major_gc.c,v
retrieving revision 1.37
retrieving revision 1.39
diff -u -r1.37 -r1.39
--- major_gc.c	2002/06/05 12:11:15	1.37
+++ major_gc.c	2002/07/30 13:48:52	1.39
@@ -11,7 +11,7 @@
 /*                                                                     */
 /***********************************************************************/
 
-/* $Id: major_gc.c,v 1.37 2002/06/05 12:11:15 doligez Exp $ */
+/* $Id: major_gc.c,v 1.39 2002/07/30 13:48:52 xleroy Exp $ */
 
 #include <limits.h>
 
@@ -126,15 +126,12 @@
       if (Tag_hd (hd) < No_scan_tag){
         for (i = 0; i < size; i++){
           child = Field (v, i);
-        mark_again:
           if (Is_block (child) && Is_in_heap (child)) {
             hd = Hd_val(child);
             if (Tag_hd (hd) == Forward_tag){
-              child = Forward_val (child);
-              Field (v, i) = child;
-              goto mark_again;
+              Field (v, i) = Forward_val (child);
             }
-            if (Tag_hd(hd) == Infix_tag) {
+            else if (Tag_hd(hd) == Infix_tag) {
               child -= Infix_offset_val(child);
               hd = Hd_val(child);
             }@@ -192,15 +189,13 @@
           sz = Wosize_hd (hd);
           for (i = 1; i < sz; i++){
             curfield = Field (cur, i);
-          weak_again:
-            if (curfield != 0 && Is_block (curfield) && Is_in_heap (curfield)
-                && Is_white_val (curfield)){
+            if (curfield != 0 && Is_block (curfield) && Is_in_heap (curfield)){
               if (Tag_val (curfield) == Forward_tag){
-                curfield = Forward_val (curfield);
-                Field (cur, i) = curfield;
-                goto weak_again;
+                Field (cur, i) = Forward_val (curfield);
               }
-              Field (cur, i) = 0;
+              else if (Is_white_val (curfield)){
+                Field (cur, i) = 0;
+              }
             }
           }
           weak_prev = &Field (cur, 0);

