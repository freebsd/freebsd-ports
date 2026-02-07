--- src/globals.h.orig	2015-04-15 08:00:23 UTC
+++ src/globals.h
@@ -179,18 +179,13 @@ class Accessors {
 #endif
 };
 
-#if defined(__GNUC__) && (defined(i386) || defined(__x86_64))
 #if defined(__x86_64__)
 #define __CAS_INSTR "lock; cmpxchgq %1,%2"
 #define __ADD_INSTR "lock; xaddq %0,%1"
-#else  // defined(__x86_64__)
+#else
 #define __CAS_INSTR "lock; cmpxchgl %1,%2"
 #define __ADD_INSTR "lock; xaddl %0,%1"
-#endif  // defined(__x86_64__)
-#else  // defined(__GNUC__) && (defined(i386) || defined(__x86_64))
-#error \
-    "Cannot compile with non-x86.  Add support for atomic ops, if you want it"
-#endif  // defined(__GNUC__) && (defined(i386) || defined(__x86_64))
+#endif
 
 inline intptr_t NoBarrier_CompareAndSwap(volatile intptr_t *ptr,
                                          intptr_t old_value,
