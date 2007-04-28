--- findhier.h.orig	Sun Apr 29 00:47:16 2007
+++ findhier.h	Sun Apr 29 00:49:02 2007
@@ -6,6 +6,7 @@
  *
  */
 #include <stdio.h>
+#include <stdlib.h>
 #include <string.h>
 #include "fstruct.h"
 
@@ -31,7 +32,7 @@
 
 #ifndef isalpha
 #define isalpha(X) ( X>='A' && X<='Z' || X>='a' && X<='z' )
-#endif isalpha
+#endif /* isalpha */
 
 typedef enum formats { CIF, GDSII, MAGIC, PCSTR, VALID, TeX } FORMAT;
 
@@ -111,19 +112,21 @@
 void exit();
 char *getenv();
 
+/*
 #ifdef SYSV
 void *malloc();
 void free();
 #else
 char *malloc();
 #endif SYSV
+*/
 #ifdef _UNIX_
 #	define OPENMODE "r"
 #	define DIRDEL '/'
 #else
 #define OPENMODE "rb"
 #define DIRDEL '\\'
-#endif _UNIX_
+#endif /* _UNIX_ */
 /*
 char *getenv();
 */
