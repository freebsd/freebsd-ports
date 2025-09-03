--- dlls/ntdll/unix/signal_x86_64.c.orig	2025-08-29 19:56:01 UTC
+++ dlls/ntdll/unix/signal_x86_64.c
@@ -2061,7 +2061,7 @@ static inline BOOL check_invalid_gsbase( ucontext_t *u
     else
         arch_prctl( ARCH_GET_GS, &cur_gsbase );
 #elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-    amd64_get_gsbase( &cur_gsbase );
+    amd64_get_gsbase((void **) &cur_gsbase);
 #elif defined(__NetBSD__)
     sysarch( X86_64_GET_GSBASE, &cur_gsbase );
 #endif
