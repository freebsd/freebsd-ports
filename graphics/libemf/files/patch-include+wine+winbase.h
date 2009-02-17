--- include/wine/winbase.h.org	2009-02-17 09:53:26.000000000 +0900
+++ include/wine/winbase.h	2009-02-17 09:54:24.000000000 +0900
@@ -1802,6 +1802,7 @@
 VOID        WINAPI SetLastError(DWORD);
 #endif  /* __i386__ && __GNUC__ */
 
+#if !defined(__alpha__) && !defined(__amd64__) && !defined(__ia64__) && !defined(__sparc64__)
 /* FIXME: should handle platforms where sizeof(void*) != sizeof(long) */
 static inline PVOID WINAPI InterlockedCompareExchangePointer( PVOID *dest, PVOID xchg, PVOID compare )
 {
@@ -1813,6 +1814,7 @@
     return (PVOID)InterlockedExchange( (PLONG)dest, (LONG)val );
 }
 
+#endif
 #ifdef __WINE__
 #define GetCurrentProcess() ((HANDLE)0xffffffff)
 #define GetCurrentThread()  ((HANDLE)0xfffffffe)
