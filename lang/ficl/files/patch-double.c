--- double.c.orig	2010-09-12 15:18:07 UTC
+++ double.c
@@ -157,7 +157,7 @@ ficl2Integer ficl2IntegerMultiply(ficlIn
 
 ficl2Integer ficl2IntegerDecrement(ficl2Integer x)
 {
-	if (x.low == INT_MIN)
+	if (x.low == INTMAX_MIN)
 		x.high--;
 	x.low--;
 
@@ -168,16 +168,11 @@ ficl2Integer ficl2IntegerDecrement(ficl2
 ficl2Unsigned ficl2UnsignedAdd(ficl2Unsigned x, ficl2Unsigned y)
 {
     ficl2Unsigned result;
-    int carry;
     
     result.high = x.high + y.high;
     result.low = x.low + y.low;
 
-
-    carry  = ((x.low | y.low) & FICL_CELL_HIGH_BIT) && !(result.low & FICL_CELL_HIGH_BIT);
-    carry |= ((x.low & y.low) & FICL_CELL_HIGH_BIT);
-
-    if (carry)
+    if (result.low < y.low)
     {
         result.high++;
     }
