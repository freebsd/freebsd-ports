--- ./popt.c.orig	Thu Aug 22 18:17:44 2002
+++ ./popt.c	Wed Apr  4 12:25:14 2007
@@ -14,6 +14,9 @@
 #include <float.h>
 #endif
 #include <math.h>
+#ifdef __FreeBSD__
+#include <machine/float.h>
+#endif
 
 #include "findme.h"
 #include "poptint.h"
@@ -1153,7 +1156,7 @@
     /*@=nullderef@*/
 }
 
-const char *const poptStrerror(const int error)
+const char * poptStrerror(const int error)
 {
     switch (error) {
       case POPT_ERROR_NOARG:
