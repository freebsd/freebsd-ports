--- spice3f5/common/src/include/misc.h.orig	1994-01-29 19:14:17 UTC
+++ spice3f5/common/src/include/misc.h
@@ -5,6 +5,10 @@ Copyright 1990 Regents of the University
 #ifndef MISC_H
 #define MISC_H
 
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
 #define BSIZE_SP      512
 
 #ifdef HAS_EXIT1
@@ -81,12 +85,16 @@ extern void srandom();
 #    define srandom	srand
 #  endif
 
+/*
 extern char *calloc();
 extern char *malloc();
+*/
 extern char *realloc();
 extern char *getenv();
 extern int errno;
+#if !(defined(BSD) && (BSD >= 199306))
 extern char *sys_errlist[];
+#endif
 extern char *getenv();
 extern char *getwd();
 extern int rand();
@@ -109,12 +117,14 @@ extern void clearerr();
 #    endif /* clearerr */
 #  endif /* HAS_CLEARERR */
 
+#if !(defined(BSD) && (BSD >= 199306))
 #  ifndef bzero
 extern int bzero();
 #  endif
 #  ifndef bcopy
 extern void bcopy();
 #  endif
+#endif
 
 #  ifndef index
 #    ifdef HAS_INDEX
