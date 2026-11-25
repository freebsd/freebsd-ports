Declare tlb_flush() and tlb_flush_all() with (void). On i386, MEMCALL is
__attribute__((fastcall)), which clang refuses on functions without a
prototype.

--- i386c/ia32/paging.h.orig	2026-11-24 15:01:13 UTC
+++ i386c/ia32/paging.h
@@ -394,8 +394,8 @@
 struct tlb_entry;
 void tlb_init(void);
 void MEMCALL tlb_update_access_flags(void);
-void MEMCALL tlb_flush();
-void MEMCALL tlb_flush_all();
+void MEMCALL tlb_flush(void);
+void MEMCALL tlb_flush_all(void);
 void MEMCALL tlb_flush_page(UINT32 laddr);
 struct tlb_entry *MEMCALL tlb_lookup(UINT32 laddr, int ucrw);
 
