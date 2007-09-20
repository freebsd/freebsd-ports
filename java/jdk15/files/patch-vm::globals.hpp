$FreeBSD$

--- ../../hotspot/src/share/vm/runtime/globals.hpp.orig	Wed May  2 04:01:50 2007
+++ ../../hotspot/src/share/vm/runtime/globals.hpp	Tue Sep 18 21:40:44 2007
@@ -130,6 +130,12 @@
 #define falseInProduct true
 #endif
 
+#if defined(_ALLBSD_SOURCE)
+#define OSUseThreadPriorities false
+#else
+#define OSUseThreadPriorities true
+#endif
+
 // develop flags are settable / visible only during development and are constant in the PRODUCT version
 // product flags are always settable / visible
 
@@ -2546,7 +2552,7 @@
           "beginning to throw OutOfMemoryErrors in each compile")           \
                                                                             \
   /* Priorities */                                                          \
-  product(bool, UseThreadPriorities, true,                                  \
+  product(bool, UseThreadPriorities, OSUseThreadPriorities,                 \
           "Use native thread priorities")	                            \
                                                                             \
   product(intx, ThreadPriorityPolicy, 0,                                    \
