--- includes/rts/storage/ClosureMacros.h.orig	2018-01-03 13:27:55 UTC
+++ includes/rts/storage/ClosureMacros.h
@@ -499,8 +499,17 @@ INLINE_HEADER StgWord8 *mutArrPtrsCard (
 
    -------------------------------------------------------------------------- */
 
-#define ZERO_SLOP_FOR_LDV_PROF     (defined(PROFILING))
-#define ZERO_SLOP_FOR_SANITY_CHECK (defined(DEBUG) && !defined(THREADED_RTS))
+#if defined(PROFILING)
+#define ZERO_SLOP_FOR_LDV_PROF 1
+#else
+#define ZERO_SLOP_FOR_LDV_PROF 0
+#endif
+
+#if defined(DEBUG) && !defined(THREADED_RTS)
+#define ZERO_SLOP_FOR_SANITY_CHECK 1
+#else
+#define ZERO_SLOP_FOR_SANITY_CHECK 0
+#endif
 
 #if ZERO_SLOP_FOR_LDV_PROF || ZERO_SLOP_FOR_SANITY_CHECK
 #define OVERWRITING_CLOSURE(c) overwritingClosure(c)
