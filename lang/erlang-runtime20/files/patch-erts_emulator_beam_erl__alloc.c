--- erts/emulator/beam/erl_alloc.c.orig	2018-03-13 20:11:05 UTC
+++ erts/emulator/beam/erl_alloc.c
@@ -122,7 +122,7 @@ typedef union {
     char align_afa[ERTS_ALC_CACHE_LINE_ALIGN_SIZE(sizeof(AFAllctr_t))];
     AOFFAllctr_t aoffa;
     char align_aoffa[ERTS_ALC_CACHE_LINE_ALIGN_SIZE(sizeof(AOFFAllctr_t))];
-} ErtsAllocatorState_t;
+} ErtsAllocatorState_t erts_align_attribute(ERTS_CACHE_LINE_SIZE);
 
 static ErtsAllocatorState_t std_alloc_state;
 static ErtsAllocatorState_t ll_alloc_state;
