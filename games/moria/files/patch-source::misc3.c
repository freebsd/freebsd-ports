$FreeBSD$

--- source/misc3.c.orig	Fri Jul 22 11:47:30 1994
+++ source/misc3.c	Sat Oct 16 16:59:14 1999
@@ -283,7 +283,7 @@
 {
   vtype out_val;
 
-  (void) sprintf(out_val, "%s: %6ld", header, num);
+  (void) sprintf(out_val, "%s:%7ld", header, num);
   put_buffer(out_val, row, column);
 }
 
@@ -317,7 +317,7 @@
 {
   vtype out_val;
 
-  (void) sprintf(out_val, "%6ld", num);
+  (void) sprintf(out_val, "%7ld", num);
   put_buffer(out_val, row, column);
 }
 
@@ -481,7 +481,7 @@
 /* Prints current gold					-RAK-	*/
 void prt_gold()
 {
-  prt_long(py.misc.au, 20, STAT_COLUMN+6);
+  prt_long(py.misc.au, 20, STAT_COLUMN+5);
 }
 
 
@@ -2070,7 +2070,7 @@
   if (p_ptr->exp > p_ptr->max_exp)
     p_ptr->max_exp = p_ptr->exp;
 
-  prt_long(p_ptr->exp, 14, STAT_COLUMN+6);
+  prt_long(p_ptr->exp, 14, STAT_COLUMN+5);
 }
 
 
