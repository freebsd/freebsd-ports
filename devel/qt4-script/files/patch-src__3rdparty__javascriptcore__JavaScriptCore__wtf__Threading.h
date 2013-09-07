From 0de22e80ac645afc3793419300d6271d95809196 Mon Sep 17 00:00:00 2001
From: Raphael Kubo da Costa <rakuco@FreeBSD.org>
Date: Tue, 11 Jun 2013 19:25:08 +0300
Subject: [PATCH] Bring in WebKit revisions 139553 and 139921.

They are primarily useful for getting rid of some libstdc++-specific
includes which break the build with libc++, and also for simplifying the
code and removing a Darwin-specific code path.

r139553 by ossy@webkit.org:
  Use sync_add_and_fetch instead of gnu_cxx::exchange_and_add
  https://bugs.webkit.org/show_bug.cgi?id=106729

  After r139514 we need atomicIncrement(int64_t volatile*) for all
  platform. Now the GCC implementation of atomicIncrement() is based on
  gnu_cxx::exchange_and_add, which doesn't support int64_t type, but
  sync_add_and_fetch does.

  Reviewed by Benjamin Poulain.

r139921 by benjamin@webkit.org:
  Use GCC's implementation of atomicIncrement/Decrement on Mac
  https://bugs.webkit.org/show_bug.cgi?id=106976

  Reviewed by Filip Pizlo.

  wtf/Atomics.h: GCC and LLVM have builtin for atomic ADD and SUB:
                 sync_add_and_fetch, sync_sub_and_fetch.

  Using them let the compiler just generate the atomic operations inline
  instead of generating a function call to LibC. It also simplify the
  code a bit.

Cherry-picked from qtscript/184fc178f4c753727445694c4830c250f53da588.

Change-Id: Id785e35944682691725947e0f329668d17ff6903
Reviewed-by: Thiago Macieira <thiago.macieira@intel.com>
---
 .../javascriptcore/JavaScriptCore/wtf/Threading.h      | 18 ++----------------
 1 file changed, 2 insertions(+), 16 deletions(-)

diff --git a/src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h b/src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h
index 8b76c0f..b3ea7d2 100644
--- src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h
+++ src/3rdparty/javascriptcore/JavaScriptCore/wtf/Threading.h
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
@@ -230,12 +222,6 @@ inline int atomicIncrement(int volatile* addend) { return InterlockedIncrement(r
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
@@ -250,8 +236,8 @@ inline int atomicDecrement(int volatile* addend) { return (int) atomic_sub_value
 #elif COMPILER(GCC) && !CPU(SPARC64) && !OS(SYMBIAN) // sizeof(_Atomic_word) != sizeof(int) on sparc64 gcc
 #define WTF_USE_LOCKFREE_THREADSAFESHARED 1
 
-inline int atomicIncrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, 1) + 1; }
-inline int atomicDecrement(int volatile* addend) { return __gnu_cxx::__exchange_and_add(addend, -1) - 1; }
+inline int atomicIncrement(int volatile* addend) { return __sync_add_and_fetch(addend, 1); }
+inline int atomicDecrement(int volatile* addend) { return __sync_sub_and_fetch(addend, 1); }
 
 #endif
 
-- 
1.8.4

