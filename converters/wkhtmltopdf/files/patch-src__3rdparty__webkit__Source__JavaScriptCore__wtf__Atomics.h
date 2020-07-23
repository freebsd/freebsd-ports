--- src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h.orig	2018-05-29 06:56:52 UTC
+++ src/3rdparty/webkit/Source/JavaScriptCore/wtf/Atomics.h
@@ -63,19 +63,11 @@
 
 #if OS(WINDOWS)
 #include <windows.h>
-#elif OS(DARWIN)
-#include <libkern/OSAtomic.h>
 #elif OS(ANDROID)
 #include <cutils/atomic.h>
 #elif OS(QNX)
 #include <atomic.h>
-#elif COMPILER(GCC) && !OS(SYMBIAN)
-#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
-#include <ext/atomicity.h>
-#else
-#include <bits/atomicity.h>
 #endif
-#endif
 
 namespace WTF {
 
@@ -89,12 +81,6 @@ inline int atomicDecrement(int* addend) { return Inter
 inline int atomicIncrement(int volatile* addend) { return InterlockedIncrement(reinterpret_cast<long volatile*>(addend)); }
 inline int atomicDecrement(int volatile* addend) { return InterlockedDecrement(reinterpret_cast<long volatile*>(addend)); }
 #endif
-
-#elif OS(DARWIN)
-#define WTF_USE_LOCKFREE_THREADSAFESHARED 1
-
-inline int atomicIncrement(int volatile* addend) { return OSAtomicIncrement32Barrier(const_cast<int*>(addend)); }
-inline int atomicDecrement(int volatile* addend) { return OSAtomicDecrement32Barrier(const_cast<int*>(addend)); }
 
 #elif OS(ANDROID)
 
