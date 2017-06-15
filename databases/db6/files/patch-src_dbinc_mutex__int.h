--- src/dbinc/mutex_int.h.orig	2016-03-28 19:45:54 UTC
+++ src/dbinc/mutex_int.h
@@ -9,6 +9,7 @@
 #ifndef _DB_MUTEX_INT_H_
 #define	_DB_MUTEX_INT_H_
 
+#include <machine/atomic.h>
 #include "dbinc/atomic.h"
 
 #if defined(__cplusplus)
@@ -506,11 +507,11 @@ typedef unsigned int tsl_t;
 #define	MUTEX_UNSET(tsl)	(*(volatile tsl_t *)(tsl) = 0)
 #define	MUTEX_INIT(tsl)         (MUTEX_UNSET(tsl), 0)
 #define	MUTEX_MEMBAR(x) \
-	({ __asm__ volatile ("dsb"); })
+	dsb(x)
 #define	MEMBAR_ENTER() \
-	({ __asm__ volatile ("dsb"); })
+	dsb()
 #define	MEMBAR_EXIT() \
-	({ __asm__ volatile ("dsb"); })
+	dsb()
 #endif
 #endif
 
@@ -652,7 +652,7 @@ MUTEX_SET(int *tsl)  {
 	 : "=&r" (__r), "+r" (tsl)
 	 :
 	 : "cr0", "memory");
-	 return (int)tsl;
+	 return (tsl != 0);
 }
 
 static inline int
