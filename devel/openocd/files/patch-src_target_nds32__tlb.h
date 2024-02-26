--- src/target/nds32_tlb.h.orig	2024-02-26 10:23:29 UTC
+++ src/target/nds32_tlb.h
@@ -22,8 +22,8 @@ enum {
 #include "nds32.h"
 
 enum {
-	PAGE_SIZE_4K = 0,
-	PAGE_SIZE_8K,
+	PAGE_SIZE_4K_BYTES = 0,
+	PAGE_SIZE_8K_BYTES,
 	PAGE_SIZE_NUM,
 };
 
