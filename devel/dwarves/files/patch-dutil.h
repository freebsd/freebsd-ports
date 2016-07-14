--- dutil.h.orig	2016-06-30 19:30:28 UTC
+++ dutil.h
@@ -15,7 +15,17 @@
 #include <stddef.h>
 #include <elf.h>
 #include <gelf.h>
+#if 0
 #include <asm/bitsperlong.h>
+#else
+# if defined(__LP64__)
+#  define __BITS_PER_LONG 64
+# elif defined(__ILP32__)
+#  define __BITS_PER_LONG 32
+# else
+#  error What are you
+# endif /* __LP64__ */
+#endif
 #include "rbtree.h"
 
 #define BITS_PER_LONG __BITS_PER_LONG
@@ -28,7 +38,9 @@
 #define __pure __attribute__ ((pure))
 #endif
 
+#ifndef roundup
 #define roundup(x,y) ((((x) + ((y) - 1)) / (y)) * (y))
+#endif
 
 static inline __attribute__((const)) bool is_power_of_2(unsigned long n)
 {
