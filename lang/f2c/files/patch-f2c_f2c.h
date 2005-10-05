--- f2c/f2c.h.orig	Mon Jan  1 12:03:53 2001
+++ f2c/f2c.h	Tue Oct  4 19:30:53 2005
@@ -6,22 +6,23 @@
 
 #ifndef F2C_INCLUDE
 #define F2C_INCLUDE
+#include <sys/types.h>
 
-typedef long int integer;
-typedef unsigned long int uinteger;
+typedef int32_t integer;
+typedef uint32_t uinteger;
 typedef char *address;
 typedef short int shortint;
 typedef float real;
 typedef double doublereal;
 typedef struct { real r, i; } complex;
 typedef struct { doublereal r, i; } doublecomplex;
-typedef long int logical;
+typedef int32_t logical;
 typedef short int shortlogical;
 typedef char logical1;
 typedef char integer1;
 #ifdef INTEGER_STAR_8	/* Adjust for integer*8. */
-typedef long long longint;		/* system-dependent */
-typedef unsigned long long ulongint;	/* system-dependent */
+typedef int64_t longint;               /* system-dependent */
+typedef uint64_t ulongint;     /* system-dependent */
 #define qbit_clear(a,b)	((a) & ~((ulongint)1 << (b)))
 #define qbit_set(a,b)	((a) |  ((ulongint)1 << (b)))
 #endif
@@ -42,9 +43,9 @@
 typedef short ftnlen;
 typedef short ftnint;
 #else
-typedef long int flag;
-typedef long int ftnlen;
-typedef long int ftnint;
+typedef int32_t flag;
+typedef int32_t ftnlen;
+typedef int32_t ftnint;
 #endif
 
 /*external read, write*/
