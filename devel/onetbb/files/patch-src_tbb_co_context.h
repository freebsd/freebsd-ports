Fix mmap() call: MAP_STACK needs at least PROT_READ and PROT_WRITE

Fixes tests 29, 67 and 105:

 29 - test_resumable_tasks (SEGFAULT)
 67 - test_task (SEGFAULT)
105 - conformance_resumable_tasks (SEGFAULT)

--- src/tbb/co_context.h.orig	2026-01-22 10:49:57 UTC
+++ src/tbb/co_context.h
@@ -310,7 +310,12 @@ inline void create_coroutine(coroutine_type& c, std::s
     const std::size_t protected_stack_size = page_aligned_stack_size + 2 * REG_PAGE_SIZE;
 
     // Allocate the stack with protection property
+#if __FreeBSD__
+    // MAP_STACK needs at least PROT_READ and PROT_WRITE
+    std::uintptr_t stack_ptr = (std::uintptr_t)mmap(nullptr, protected_stack_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_STACK, -1, 0);
+#else
     std::uintptr_t stack_ptr = (std::uintptr_t)mmap(nullptr, protected_stack_size, PROT_NONE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_STACK, -1, 0);
+#endif
     __TBB_ASSERT((void*)stack_ptr != MAP_FAILED, nullptr);
 
     // Allow read write on our stack (guarded pages are still protected)
