--- erts/emulator/beam/erl_alloc.h.orig	2020-08-28 21:30:14 UTC
+++ erts/emulator/beam/erl_alloc.h
@@ -146,7 +146,7 @@ typedef struct ErtsAllocatorWrapper_t_ {
     void (*unlock)(void);
     struct ErtsAllocatorWrapper_t_* next;
 }ErtsAllocatorWrapper_t;
-ErtsAllocatorWrapper_t *erts_allctr_wrappers;
+extern ErtsAllocatorWrapper_t *erts_allctr_wrappers;
 extern int erts_allctr_wrapper_prelocked;
 extern erts_tsd_key_t erts_allctr_prelock_tsd_key;
 void erts_allctr_wrapper_prelock_init(ErtsAllocatorWrapper_t* wrapper);
