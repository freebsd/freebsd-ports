--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h.orig	2014-04-10 20:37:12.000000000 +0200
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h	2014-04-24 15:06:18.000000000 +0200
@@ -71,18 +71,10 @@
 
 #if OS(WINDOWS) && !OS(WINCE)
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
-#endif
 #endif
 
 #if USE(PTHREADS)
@@ -230,12 +222,6 @@
 inline int atomicDecrement(int volatile* addend) { return InterlockedDecrement(reinterpret_cast<long volatile*>(addend)); }
 #endif
 
-#elif OS(DARWIN)
-#define WTF_USE_LOCKFREE_THREADSAFESHARED 1
-
-inline int atomicIncrement(int volatile* addend) { return OSAtomicIncrement32Barrier(const_cast<int*>(addend)); }
-inline int atomicDecrement(int volatile* addend) { return OSAtomicDecrement32Barrier(const_cast<int*>(addend)); }
-
 #elif OS(ANDROID)
 
 inline int atomicIncrement(int volatile* addend) { return android_atomic_inc(addend); }
