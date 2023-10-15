--- src/x86seg.c.orig	2020-12-01 19:49:05 UTC
+++ src/x86seg.c
@@ -3058,7 +3058,7 @@ void x86_smi_enter(void)
         {
                 uint32_t base;
 
-                if (!cyrix.smhr & SMHR_VALID)
+                if (!(cyrix.smhr & SMHR_VALID))
                         cyrix.smhr = (cyrix.arr[3].base + cyrix.arr[3].size) | SMHR_VALID;
                 base = cyrix.smhr & SMHR_ADDR_MASK;
 
