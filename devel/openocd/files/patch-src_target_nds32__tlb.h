--- src/target/nds32_tlb.h.orig	2022-09-18 13:46:16 UTC
+++ src/target/nds32_tlb.h
@@ -10,6 +10,13 @@
 
 #include "nds32.h"
 
+#ifdef PAGE_SIZE_4K
+# undef PAGE_SIZE_4K
+#endif
+#ifdef PAGE_SIZE_8K
+# undef PAGE_SIZE_8k
+#endif
+
 enum {
 	PAGE_SIZE_4K = 0,
 	PAGE_SIZE_8K,
