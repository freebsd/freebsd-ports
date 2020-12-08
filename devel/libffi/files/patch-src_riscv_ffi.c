--- src/riscv/ffi.c.orig	2019-10-31 14:49:54 UTC
+++ src/riscv/ffi.c
@@ -417,7 +417,9 @@ ffi_status ffi_prep_closure_loc(ffi_clos
     closure->fun = fun;
     closure->user_data = user_data;
 
+#if !defined(__FreeBSD__)
     __builtin___clear_cache(codeloc, codeloc + FFI_TRAMPOLINE_SIZE);
+#endif
 
     return FFI_OK;
 }
