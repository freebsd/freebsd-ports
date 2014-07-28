--- taipan.c.orig	Fri Mar 15 15:05:41 2002
+++ taipan.c	Fri Mar 15 15:08:30 2002
@@ -2572,7 +2572,7 @@
          amount = get_num(9);
          if (amount == -1)
          {
-            amount = cash;
+            amount = repair_price;
          }
          if (amount <= cash)
          {
