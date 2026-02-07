--- src/core/uae/fpp.c.orig	2005-06-25 14:27:52 UTC
+++ src/core/uae/fpp.c
@@ -13,35 +13,35 @@
 
 void fdbcc_opp (uae_u32 opcode, uae_u16 extra)
 {
-    abort();
+    uae_abort();
 }
 
 void fscc_opp (uae_u32 opcode, uae_u16 extra)
 {
-    abort();
+    uae_abort();
 }
 
 void ftrapcc_opp (uae_u32 opcode, uaecptr oldpc)
 {
-    abort();
+    uae_abort();
 }
 
 void fbcc_opp (uae_u32 opcode, uaecptr pc, uae_u32 extra)
 {
-    abort();
+    uae_abort();
 }
 
 void fsave_opp (uae_u32 opcode)
 {
-    abort();
+    uae_abort();
 }
 
 void frestore_opp (uae_u32 opcode)
 {
-    abort();
+    uae_abort();
 }
 
 void fpp_opp (uae_u32 opcode, uae_u16 extra)
 {
-    abort();
+    uae_abort();
 }
