--- libdb/dbinc/mutex.h.orig	Mon Nov  8 01:02:41 2004
+++ libdb/dbinc/mutex.h	Mon Nov  8 01:03:04 2004
@@ -729,31 +729,6 @@
 #endif
 
 /*********************************************************************
- * amd64/gcc assembly.
- *********************************************************************/
-#ifdef HAVE_MUTEX_X86_64_GCC_ASSEMBLY
-typedef unsigned char tsl_t;
-
-#ifdef LOAD_ACTUAL_MUTEX_CODE
-/*
- * For gcc/amd64, 0 is clear, 1 is set.
- */
-#define  MUTEX_SET(tsl) ({           \
-	register tsl_t *__l = (tsl);          \
-	int __r;              \
-	asm volatile("mov $1,%%rax; lock; xchgb %1,%%al; xor $1,%%rax"\
-		: "=&a" (__r), "=m" (*__l)          \
-		: "1" (*__l)            \
-		);                \
-	__r & 1;              \
-})
-
-#define  MUTEX_UNSET(tsl)  (*(tsl) = 0)
-#define  MUTEX_INIT(tsl)   MUTEX_UNSET(tsl)
-#endif
-#endif
-
-/*********************************************************************
  * x86_64/gcc assembly.
  *********************************************************************/
 #ifdef HAVE_MUTEX_X86_64_GCC_ASSEMBLY
