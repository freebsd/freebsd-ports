--- mozilla/js/src/jslock.cpp.orig	2010-01-23 20:35:45.000000000 +0100
+++ mozilla/js/src/jslock.cpp	2010-01-23 20:37:35.000000000 +0100
@@ -160,8 +160,13 @@
     unsigned int res;
 
     __asm__ __volatile__ (
-                  "stbar\n"
-                  "cas [%1],%2,%3\n"
+                  "membar #StoreLoad | #LoadLoad\n"
+#                 if defined (__sparc64__)
+                    "casx [%1],%2,%3\n"
+#                 else
+                    "cas [%1],%2,%3\n" /* 32-bit version */
+#                 endif
+                  "membar #StoreLoad | #LoadLoad\n"
                   "cmp %2,%3\n"
                   "be,a 1f\n"
                   "mov 1,%0\n"
