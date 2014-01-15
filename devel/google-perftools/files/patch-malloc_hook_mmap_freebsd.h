--- src/malloc_hook_mmap_freebsd.h	2014-01-15 00:52:17.000000000 -0800
+++ src/malloc_hook_mmap_freebsd.h	2014-01-15 01:12:48.000000000 -0800
@@ -39,6 +39,7 @@
 #include <sys/syscall.h>
 #include <sys/mman.h>
 #include <errno.h>
+#include <dlfcn.h>
 
 // Make sure mmap doesn't get #define'd away by <sys/mman.h>
 #undef mmap
@@ -73,43 +74,11 @@
 }
 
 static inline void* do_sbrk(intptr_t increment) {
-  void* curbrk = 0;
+  static void *(*libc_sbrk)(intptr_t);
+  if (libc_sbrk == NULL)
+    libc_sbrk = (void *(*)(intptr_t))dlsym(RTLD_NEXT, "sbrk");
 
-#if defined(__x86_64__) || defined(__amd64__)
-# ifdef PIC
-  __asm__ __volatile__(
-      "movq .curbrk@GOTPCREL(%%rip), %%rdx;"
-      "movq (%%rdx), %%rax;"
-      "movq %%rax, %0;"
-      : "=r" (curbrk)
-      :: "%rdx", "%rax");
-# else
-  __asm__ __volatile__(
-      "movq .curbrk(%%rip), %%rax;"
-      "movq %%rax, %0;"
-      : "=r" (curbrk)
-      :: "%rax");
-# endif
-#else
-  __asm__ __volatile__(
-      "movl .curbrk, %%eax;"
-      "movl %%eax, %0;"
-      : "=r" (curbrk)
-      :: "%eax");
-#endif
-
-  if (increment == 0) {
-    return curbrk;
-  }
-
-  char* prevbrk = static_cast<char*>(curbrk);
-  void* newbrk = prevbrk + increment;
-
-  if (brk(newbrk) == -1) {
-    return reinterpret_cast<void*>(static_cast<intptr_t>(-1));
-  }
-
-  return prevbrk;
+  return libc_sbrk(increment);
 }
 
 
