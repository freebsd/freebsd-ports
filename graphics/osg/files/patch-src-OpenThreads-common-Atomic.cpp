--- src/OpenThreads/common/Atomic.cpp.orig	2011-04-19 13:40:22.000000000 +0200
+++ src/OpenThreads/common/Atomic.cpp	2013-09-18 11:26:03.000000000 +0200
@@ -143,7 +143,7 @@
 AtomicPtr::assign(void* ptrNew, const void* const ptrOld)
 {
 #if defined(_OPENTHREADS_ATOMIC_USE_GCC_BUILTINS)
-    return __sync_bool_compare_and_swap(&_ptr, ptrOld, ptrNew);
+    return __sync_bool_compare_and_swap(&_ptr, (void *)ptrOld, ptrNew);
 #elif defined(_OPENTHREADS_ATOMIC_USE_WIN32_INTERLOCKED)
     return ptrOld == InterlockedCompareExchangePointer((PVOID volatile*)&_ptr, (PVOID)ptrNew, (PVOID)ptrOld);
 #elif defined(_OPENTHREADS_ATOMIC_USE_BSD_ATOMIC)
