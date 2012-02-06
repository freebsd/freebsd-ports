--- ./newlib/libc/include/stdint.h.orig	2009-04-24 21:55:07.000000000 +0000
+++ ./newlib/libc/include/stdint.h	2012-01-25 19:33:12.000000000 +0000
@@ -30,11 +30,9 @@
 #define __have_longlong64 1
 #endif
 
-/* Check if "long" is 64bit or 32bit wide */
+/* Check if "long" is 64bit */
 #if __STDINT_EXP(LONG_MAX) > 0x7fffffff
 #define __have_long64 1
-#elif __STDINT_EXP(LONG_MAX) == 0x7fffffff && !defined(__SPU__)
-#define __have_long32 1
 #endif
 
 #if __STDINT_EXP(SCHAR_MAX) == 0x7f
