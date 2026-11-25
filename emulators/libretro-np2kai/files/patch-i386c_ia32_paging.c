Declare tlb_flush() and tlb_flush_all() with (void). On i386, MEMCALL is
__attribute__((fastcall)), which clang refuses on functions without a
prototype.

--- i386c/ia32/paging.c.orig	2026-11-24 15:01:13 UTC
+++ i386c/ia32/paging.c
@@ -1587,7 +1587,7 @@
 }
 
 void MEMCALL
-tlb_flush()
+tlb_flush(void)
 {
 	struct tlb_entry *ep;
 	int i;
@@ -1611,7 +1611,7 @@
 }
 
 void MEMCALL
-tlb_flush_all()
+tlb_flush_all(void)
 {
 	tlb_init();
 }
