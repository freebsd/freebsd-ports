--- reuse/m2c/SYSTEM_.h.orig	Wed Feb 16 00:26:45 1994
+++ reuse/m2c/SYSTEM_.h	Fri Dec 17 09:21:56 2004
@@ -16,10 +16,18 @@
 /*									*/
 /************************************************************************/
 
+#define DEFINITION_SYSTEM_
+
+# include <stdlib.h>
+# include <string.h>
+# include <limits.h>
+
 # ifdef __STDC__
 # define ARGS(parameters)	parameters
+# define NOARGS			void
 # else
 # define ARGS(parameters)	()
+# define NOARGS			
 # endif
 
 /*
@@ -30,6 +38,7 @@
 #define TRUE		((BOOLEAN)1)
 
 #define NIL		0L
+#define DEAD_ALLOCATE	0xd0d0d0d0d0d0d0d0L
 
 /*
  *	Definition of basic types
@@ -55,7 +64,7 @@
 
 typedef unsigned long	BITSET;
 
-typedef void		(*PROC)();
+typedef void		(*PROC)(NOARGS);
 
 typedef unsigned char	WORD;
 typedef WORD		BYTE;
@@ -85,14 +94,14 @@
 #define TRUNC(x)	((CARDINAL) (x))
 #define VAL(T,x)	((T) (x))
 
-#define MIN_SHORTINT	(-32768)
-#define MAX_SHORTINT	32767
-#define MIN_LONGINT	(-2147483648L)
-#define MAX_LONGINT	2147483647L
+#define MIN_SHORTINT	__SHRT_MIN
+#define MAX_SHORTINT	__SHRT_MAX
+#define MIN_LONGINT	__INT_MIN
+#define MAX_LONGINT	__INT_MAX
 #define MIN_SHORTCARD	0
 #define MAX_SHORTCARD	65535
 #define MIN_LONGCARD	((LONGCARD)0L)
-#define MAX_LONGCARD	((LONGCARD)4294967295L)
+#define MAX_LONGCARD	((LONGCARD)__ULONG_MAX)
 
 #define MIN_BOOLEAN	FALSE
 #define MAX_BOOLEAN	TRUE
@@ -129,7 +138,12 @@
 #define SYSTEM_MaxSet		(sizeof (unsigned long) * 8 - 1)
 
 #define SET_ELEM(el)		(0X1L << (el))
-#define SET_cRNG(lo,hi)		((lo) <= (hi) ? ((unsigned) (((unsigned) ~0X0L) >> (lo) << (lo) + SYSTEM_MaxSet - (hi))) >> SYSTEM_MaxSet - (hi) : 0X0L)
+#define SET_cRNG(lo,hi)		\
+	((lo) <= (hi) 		\
+		? (( (~(0X0UL)) >> (lo) )	\
+			<< (lo + SYSTEM_MaxSet - hi) )	\
+			>> (SYSTEM_MaxSet - hi) 	\
+		: 0X0L)
 #define SET_RANGE(lo,hi)	SET_RANGE1((CARDINAL)(lo), (CARDINAL)(hi))
 
 extern unsigned long SET_RANGE1 ARGS((CARDINAL lo, CARDINAL hi));
@@ -177,7 +191,7 @@
 #define OPEN_ARRAY_LOCALS	char *BLOCK_POINTER, *FREE_POINTER;
 #define ALLOC_OPEN_ARRAYS(size, arrays)	\
 	BLOCK_POINTER = FREE_POINTER = \
-		malloc((unsigned)((size) + (arrays) * (SYSTEM_ALIGN - 1)));
+		calloc(1, (unsigned)((size) + (arrays) * (SYSTEM_ALIGN - 1)));
 #define FREE_OPEN_ARRAYS	free(BLOCK_POINTER);
 
 #endif
@@ -205,21 +219,4 @@
 
 extern void CaseError ARGS((char file[], int line));
 extern void ReturnError ARGS((char file[], int line));
-
-/*
- *	Definition of library functions
- */
-
-#ifdef StackAlloc
-extern char *alloca();
-#else
-/* #include "malloc.h"	*/
-extern char *malloc();
-extern void free();
-#endif
-
-# ifndef BCOPY
-/* extern char *memcpy(); */
-# endif
-extern char *strncpy();
-extern void exit();
+extern void BEGIN_MODULE ARGS((NOARGS));
