--- 3rd/bee.lua/bee/thread/spinlock.h.orig	2022-09-13 00:54:42 UTC
+++ 3rd/bee.lua/bee/thread/spinlock.h
@@ -18,6 +18,8 @@
         asm volatile ("div %0, %0, zero" : "=r" (dummy));
         asm volatile ("" ::: "memory");
     }}
+#elif defined(__powerpc__)
+    namespace bee { inline void cpu_relax() { asm volatile("ori 0,0,0" ::: "memory"); }}
 #else
     #error unsupport platform
 #endif
