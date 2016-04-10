--- taipan.c.orig	2001-12-31 16:09:20 UTC
+++ taipan.c
@@ -2572,7 +2572,7 @@ void mchenry(void)
          amount = get_num(9);
          if (amount == -1)
          {
-            amount = cash;
+            amount = repair_price;
          }
          if (amount <= cash)
          {
@@ -2705,8 +2705,8 @@ void final_stats(void)
       bank         = 0;
       hkw_[0]      = 0;
       hkw_[1]      = 0;
+      hkw_[2]      = 0;
       hkw_[3]      = 0;
-      hkw_[4]      = 0;
       hold_[0]     = 0;
       hold_[1]     = 0;
       hold_[2]     = 0;
