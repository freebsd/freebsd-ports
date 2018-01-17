--- include/iprt/cdefs.h.orig	2018-01-15 14:49:42 UTC
+++ include/iprt/cdefs.h
@@ -2214,6 +2214,8 @@
  */
 #if defined(__cplusplus) && RT_GNUC_PREREQ(4, 4)
 # define RT_OFFSETOF(type, member)              ( (int)(uintptr_t)&( ((type *)(void *)0x1000)->member) - 0x1000 )
+#elif RT_CLANG_PREREQ(6, 0)
+# define RT_OFFSETOF(type, member)              ( (int)__builtin_offsetof(type, member) )
 #else
 # define RT_OFFSETOF(type, member)              ( (int)(uintptr_t)&( ((type *)(void *)0)->member) )
 #endif
@@ -2232,6 +2234,8 @@
  */
 #if defined(__cplusplus) && RT_GNUC_PREREQ(4, 4)
 # define RT_UOFFSETOF(type, member)             ( (uintptr_t)&( ((type *)(void *)0x1000)->member) - 0x1000 )
+#elif RT_CLANG_PREREQ(6, 0)
+# define RT_UOFFSETOF(type, member)             ( (unsigned)__builtin_offsetof(type, member) )
 #else
 # define RT_UOFFSETOF(type, member)             ( (uintptr_t)&( ((type *)(void *)0)->member) )
 #endif
@@ -2244,7 +2248,11 @@
  * @param   member  Member.
  * @param   addend  The addend to add to the offset.
  */
-#define RT_OFFSETOF_ADD(type, member, addend)   ( (int)RT_UOFFSETOF_ADD(type, member, addend) )
+#if RT_CLANG_PREREQ(6, 0)
+# define RT_OFFSETOF_ADD(type, member, addend)  ( (int)(__builtin_offsetof(type, member) + addend) )
+#else 
+# define RT_OFFSETOF_ADD(type, member, addend)  ( (int)RT_UOFFSETOF_ADD(type, member, addend) )
+#endif
 
 /** @def RT_UOFFSETOF_ADD
  * RT_UOFFSETOF with an addend.
@@ -2254,7 +2262,11 @@
  * @param   member  Member.
  * @param   addend  The addend to add to the offset.
  */
-#define RT_UOFFSETOF_ADD(type, member, addend)  ( (uintptr_t)&( ((type *)(void *)(uintptr_t)(addend))->member) )
+#if RT_CLANG_PREREQ(6, 0)
+# define RT_UOFFSETOF_ADD(type, member, addend) ( (unsigned)(__builtin_offsetof(type, member) + addend) )
+#else
+# define RT_UOFFSETOF_ADD(type, member, addend) ( (uintptr_t)&( ((type *)(void *)(uintptr_t)(addend))->member) )
+#endif
 
 /** @def RT_SIZEOFMEMB
  * Get the size of a structure member.
@@ -2517,28 +2529,28 @@
 
 /** @def RT_BYTE1
  * Gets the first byte of something. */
-#define RT_BYTE1(a)                             ( (a)         & 0xff )
+#define RT_BYTE1(a)                             ( (uint8_t)((a)         & 0xff) )
 /** @def RT_BYTE2
  * Gets the second byte of something. */
-#define RT_BYTE2(a)                             ( ((a) >>  8) & 0xff )
+#define RT_BYTE2(a)                             ( (uint8_t)(((a) >>  8) & 0xff) )
 /** @def RT_BYTE3
  * Gets the second byte of something. */
-#define RT_BYTE3(a)                             ( ((a) >> 16) & 0xff )
+#define RT_BYTE3(a)                             ( (uint8_t)(((a) >> 16) & 0xff) )
 /** @def RT_BYTE4
  * Gets the fourth byte of something. */
-#define RT_BYTE4(a)                             ( ((a) >> 24) & 0xff )
+#define RT_BYTE4(a)                             ( (uint8_t)(((a) >> 24) & 0xff) )
 /** @def RT_BYTE5
  * Gets the fifth byte of something. */
-#define RT_BYTE5(a)                             ( ((a) >> 32) & 0xff )
+#define RT_BYTE5(a)                             ( (uint8_t)(((a) >> 32) & 0xff) )
 /** @def RT_BYTE6
  * Gets the sixth byte of something. */
-#define RT_BYTE6(a)                             ( ((a) >> 40) & 0xff )
+#define RT_BYTE6(a)                             ( (uint8_t)(((a) >> 40) & 0xff) )
 /** @def RT_BYTE7
  * Gets the seventh byte of something. */
-#define RT_BYTE7(a)                             ( ((a) >> 48) & 0xff )
+#define RT_BYTE7(a)                             ( (uint8_t)(((a) >> 48) & 0xff) )
 /** @def RT_BYTE8
  * Gets the eight byte of something. */
-#define RT_BYTE8(a)                             ( ((a) >> 56) & 0xff )
+#define RT_BYTE8(a)                             ( (uint8_t)(((a) >> 56) & 0xff) )
 
 
 /** @def RT_LODWORD
