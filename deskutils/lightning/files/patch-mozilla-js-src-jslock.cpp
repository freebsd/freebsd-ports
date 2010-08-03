--- mozilla/js/src/jslock.cpp.orig	2010-01-23 15:40:12.000000000 +0100
+++ mozilla/js/src/jslock.cpp	2010-01-23 15:45:20.000000000 +0100
@@ -133,7 +133,7 @@
     return (int)res;
 }
 
-#elif defined(SOLARIS) && defined(sparc) && defined(ULTRA_SPARC)
+#elif defined(__sparc)
 
 static JS_ALWAYS_INLINE int
 NativeCompareAndSwap(jsword *w, jsword ov, jsword nv)
@@ -142,13 +142,18 @@
     unsigned int res;
     JS_ASSERT(ov != nv);
     asm volatile ("\
-stbar\n\
-cas [%1],%2,%3\n\
-cmp %2,%3\n\
-be,a 1f\n\
-mov 1,%0\n\
-mov 0,%0\n\
-1:"
+                  membar #StoreLoad | #LoadLoad\n"
+#                 if defined (__sparc64__)
+                    "casx [%1],%2,%3\n"
+#                 else
+                    "cas [%1],%2,%3\n" /* 32-bit version */
+#                 endif
+                  "membar #StoreLoad | #LoadLoad\n"
+                  "cmp %2,%3\n"
+                  "be,a 1f\n"
+                  "mov 1,%0\n"
+                  "mov 0,%0\n"
+                  "1:"
                   : "=r" (res)
                   : "r" (w), "r" (ov), "r" (nv));
     return (int)res;
