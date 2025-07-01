Work around:

SGAtomic.cxx:48:5: error: ISO C++17 does not allow 'register' storage class specifier [-Wregister]

to fix build on i386 as Simgear uses CMAKE_CXX_STANDARD=17

--- simgear/structure/SGAtomic.cxx.orig	2025-06-30 14:48:03 UTC
+++ simgear/structure/SGAtomic.cxx
@@ -29,7 +29,7 @@
 #if defined(_WIN32)
 # include <windows.h>
 #elif defined(GCC_ATOMIC_BUILTINS_FOUND)
-#elif defined(__GNUC__) && defined(__i386__)
+#elif (__cplusplus < 201703L) && defined(__GNUC__) && defined(__i386__)
 #elif defined(SGATOMIC_USE_MUTEX)
 # include <mutex>
 #else
@@ -43,7 +43,7 @@ SGAtomic::operator++()
     return InterlockedIncrement(reinterpret_cast<long volatile*>(&mValue));
 #elif defined(GCC_ATOMIC_BUILTINS_FOUND)
     return __sync_add_and_fetch(&mValue, 1);
-#elif defined(__GNUC__) && defined(__i386__)
+#elif (__cplusplus < 201703L) && defined(__GNUC__) && defined(__i386__)
     register volatile unsigned* mem = reinterpret_cast<volatile unsigned*>(&mValue);
     register unsigned result;
     __asm__ __volatile__("lock; xadd{l} {%0,%1|%1,%0}"
@@ -64,7 +64,7 @@ SGAtomic::operator--()
     return InterlockedDecrement(reinterpret_cast<long volatile*>(&mValue));
 #elif defined(GCC_ATOMIC_BUILTINS_FOUND)
     return __sync_sub_and_fetch(&mValue, 1);
-#elif defined(__GNUC__) && defined(__i386__)
+#elif (__cplusplus < 201703L) && defined(__GNUC__) && defined(__i386__)
     register volatile unsigned* mem = reinterpret_cast<volatile unsigned*>(&mValue);
     register unsigned result;
     __asm__ __volatile__("lock; xadd{l} {%0,%1|%1,%0}"
@@ -85,7 +85,7 @@ SGAtomic::operator unsigned() const
 #elif defined(GCC_ATOMIC_BUILTINS_FOUND)
     __sync_synchronize();
     return mValue;
-#elif defined(__GNUC__) && defined(__i386__)
+#elif (__cplusplus < 201703L) && defined(__GNUC__) && defined(__i386__)
     __asm__ __volatile__("": : : "memory");
     return mValue;
 #else
@@ -102,7 +102,7 @@ SGAtomic::compareAndExchange(unsigned oldValue, unsign
     return oldValue == InterlockedCompareExchange(lvPtr, newValue, oldValue);
 #elif defined(GCC_ATOMIC_BUILTINS_FOUND)
     return __sync_bool_compare_and_swap(&mValue, oldValue, newValue);
-#elif defined(__GNUC__) && defined(__i386__)
+#elif (__cplusplus < 201703L) && defined(__GNUC__) && defined(__i386__)
     register volatile unsigned* mem = reinterpret_cast<volatile unsigned*>(&mValue);
     unsigned before;
     __asm__ __volatile__("lock; cmpxchg{l} {%1,%2|%1,%2}"
