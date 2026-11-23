--- contrib/llvm-project/llvm/lib/Support/Unix/Process.inc.orig	2026-11-10 12:08:17 UTC
+++ contrib/llvm-project/llvm/lib/Support/Unix/Process.inc
@@ -25,7 +25,7 @@
 #if defined(HAVE_MALLINFO) || defined(HAVE_MALLINFO2)
 #include <malloc.h>
 #endif
-#if defined(HAVE_MALLCTL)
+#if 1
 #include <malloc_np.h>
 #endif
 #ifdef HAVE_MALLOC_MALLOC_H
@@ -99,13 +99,13 @@ size_t Process::GetMallocUsage() {
   malloc_statistics_t Stats;
   malloc_zone_statistics(malloc_default_zone(), &Stats);
   return Stats.size_in_use; // darwin
-#elif defined(HAVE_MALLCTL)
+#elif 1
   size_t alloc, sz;
   sz = sizeof(size_t);
   if (mallctl("stats.allocated", &alloc, &sz, NULL, 0) == 0)
     return alloc;
   return 0;
-#elif defined(HAVE_SBRK)
+#elif 0
   // Note this is only an approximation and more closely resembles
   // the value returned by mallinfo in the arena field.
   static char *StartOfMemory = reinterpret_cast<char *>(::sbrk(0));
