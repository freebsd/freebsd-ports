--- textio/txOutput.c.orig	Tue Dec  9 16:38:35 2003
+++ textio/txOutput.c	Tue Dec  9 16:39:01 2003
@@ -18,7 +18,7 @@
 
 #ifndef lint
 static char rcsid[] = "$Header: /ufs/repository/magic/textio/txOutput.c,v 1.4 2001/02/21 15:52:52 tim Exp $";
-#endif  not lint
+#endif
 
 #include <stdio.h>
 #ifndef	SYSV
@@ -26,7 +26,7 @@
 #include <strings.h>
 #else
 #include <string.h>
-#endif SYSV
+#endif
 #include <sys/stat.h>
 #include <unistd.h>
 #include "misc/magsgtty.h"
@@ -42,8 +42,8 @@
 #include "utils/malloc.h"
 
 #ifndef	NO_VARARGS
-#include <varargs.h>
-#endif	NO_VARARGS
+#include <stdarg.h>
+#endif
 
 /* When a pipe has been opened to "more", the following variables
  * keep track of the file and process.  The "TxMoreFile" variable is
@@ -82,20 +82,15 @@
  /*VARARGS0*/
 
 void
-txFprintfBasic(va_alist)
-va_dcl
+txFprintfBasic(FILE *f, char *fmt, ...)
 {
     va_list args;
-    char *fmt;
-    FILE *f;
 
-    va_start(args);
-    f = va_arg(args, FILE *);
-    fmt = va_arg(args, char *);
+    va_start(args, fmt);
     (void) GrVfprintf(f, fmt, args);
     va_end(args);
 }
-#else	NO_VARARGS
+#else
 
  /*VARARGS0*/
 
@@ -107,7 +102,7 @@
     (void) GrFprintf(f, format, a1, a2, a3, a4, a5, a6, a7, a8, a9, 
 		     a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a20);
 }
-#endif	NO_VARARGS
+#endif
 
 
 /*
@@ -135,11 +130,9 @@
  /*VARARGS0*/
 
 void
-TxPrintf(va_alist)
-va_dcl
+TxPrintf(char *fmt, ...)
 {
     va_list args;
-    char *fmt;
     FILE *f;
 
     if (txPrintFlag)
@@ -156,16 +149,14 @@
 	if (txHavePrompt)
 	{
 	    TxUnPrompt();
-	    va_start(args);
-	    fmt = va_arg(args, char *);
+	    va_start(args, fmt);
 	    (void) GrVfprintf(f, fmt, args);
 	    va_end(args);
 	    TxPrompt();
 	}
 	else 
 	{
-	    va_start(args);
-	    fmt = va_arg(args, char *);
+	    va_start(args, fmt);
 	    (void) GrVfprintf(f, fmt, args);
 	    va_end(args);
 	}
@@ -173,7 +164,7 @@
 	return;
     }
 }
-#else	NO_VARARGS
+#else
 
  /*VARARGS1*/
 
@@ -212,7 +203,7 @@
 	return;
     }
 }
-#endif	NO_VARARGS
+#endif
 
 
 /*
@@ -306,11 +297,9 @@
 #ifndef	NO_VARARGS
 
 void
-TxError(va_alist)
-va_dcl
+TxError(char *fmt, ...)
 {
     va_list args;
-    char *fmt;
     FILE *f;
 
     (void) fflush(stdout);
@@ -321,22 +310,20 @@
     if (txHavePrompt)
     {
 	TxUnPrompt();
-	va_start(args);
-	fmt = va_arg(args, char *);
+	va_start(args, fmt);
 	(void) GrVfprintf(f, fmt, args);
 	va_end(args);
 	TxPrompt();
     }
     else {
-	va_start(args);
-	fmt = va_arg(args, char *);
+	va_start(args, fmt);
 	(void) GrVfprintf(f, fmt, args);
 	va_end(args);
     }
     (void) fflush(stderr);
 }
 
-#else	NO_VARARGS
+#else
 
  /*VARARGS1*/
 
@@ -364,7 +351,7 @@
     }
     (void) fflush(stderr);
 }
-#endif	NO_VARARGS
+#endif
 
 
 /*
@@ -482,7 +469,7 @@
     int status;
 #else
     union wait status;
-#endif SYSV
+#endif
 */
     /* TxMoreFile may be NULL if the "more" executable was not found */
     if (TxMoreFile == NULL) return;
@@ -532,5 +519,5 @@
 
     return (ferror(iop) ? EOF : len);
 }
-#endif  NEED_VFPRINTF
+#endif
 
