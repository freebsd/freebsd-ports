--- sys/regex.c.orig	Fri Jun 30 13:56:01 1995
+++ ./sys/regex.c	Wed Aug 26 03:14:57 1998
@@ -41,6 +41,9 @@
 #include <stdio.h>
 #include <sys/types.h>
 #endif
+#if __FreeBSD__ >= 3
+#include <sys/types.h>
+#endif
 #include <regex.h>
 
 static regex_t REXP;
