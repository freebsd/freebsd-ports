--- lisp-kernel/gc.h.orig	2020-04-19 21:32:56 UTC
+++ lisp-kernel/gc.h
@@ -62,8 +62,8 @@
 extern LispObj GCarealow, GCareadynamiclow;
 extern natural GCndnodes_in_area, GCndynamic_dnodes_in_area;
 extern bitvector GCmarkbits, GCdynamic_markbits,managed_static_refbits,global_refidx,dynamic_refidx,managed_static_refidx;
-LispObj *global_reloctab, *GCrelocptr;
-LispObj GCfirstunmarked;
+extern LispObj *global_reloctab, *GCrelocptr;
+extern LispObj GCfirstunmarked;
 
 extern natural lisp_heap_gc_threshold;
 extern natural lisp_heap_notify_threshold;
@@ -83,7 +83,7 @@ void gc(TCR *, signed_natural);
 int change_hons_area_size(TCR *, signed_natural);
 void delete_protected_area(protected_area_ptr);
 Boolean egc_control(Boolean, BytePtr);
-Boolean free_segments_zero_filled_by_OS;
+extern Boolean free_segments_zero_filled_by_OS;
 Boolean new_heap_segment(ExceptionInformation *, natural, Boolean , TCR *, Boolean *);
 void platform_new_heap_segment(ExceptionInformation *, TCR*, BytePtr, BytePtr);
 /* an type representing 1/4 of a natural word */
@@ -153,19 +153,19 @@ void report_paging_info_delta(FILE*, paging_info *, pa
 #define GC_TRAP_FUNCTION_FREEZE 129
 #define GC_TRAP_FUNCTION_THAW 130
 
-Boolean GCDebug, GCverbose, just_purified_p;
-bitvector GCmarkbits, GCdynamic_markbits;
-LispObj GCarealow, GCareadynamiclow;
-natural GCndnodes_in_area, GCndynamic_dnodes_in_area;
-LispObj GCweakvll,GCdwsweakvll;
-LispObj GCephemeral_low;
-natural GCn_ephemeral_dnodes;
-natural GCstack_limit;
+extern Boolean GCDebug, GCverbose, just_purified_p;
+extern bitvector GCmarkbits, GCdynamic_markbits;
+extern LispObj GCarealow, GCareadynamiclow;
+extern natural GCndnodes_in_area, GCndynamic_dnodes_in_area;
+extern LispObj GCweakvll,GCdwsweakvll;
+extern LispObj GCephemeral_low;
+extern natural GCn_ephemeral_dnodes;
+extern natural GCstack_limit;
 
 #if WORD_SIZE == 64
-unsigned short *_one_bits;
+extern unsigned short *_one_bits;
 #else
-const unsigned char _one_bits[256];
+extern const unsigned char _one_bits[256];
 #endif
 
 #define one_bits(x) _one_bits[x]
@@ -195,11 +195,11 @@ void gc(TCR *, signed_natural);
 /* backend-interface */
 
 typedef void (*weak_mark_fun) (LispObj);
-weak_mark_fun mark_weak_htabv, dws_mark_weak_htabv;
+extern weak_mark_fun mark_weak_htabv, dws_mark_weak_htabv;
 
 typedef void (*weak_process_fun)(void);
 
-weak_process_fun markhtabvs;
+extern weak_process_fun markhtabvs;
 
 
 #define hash_table_vector_header_count (sizeof(hash_table_vector_header)/sizeof(LispObj))
