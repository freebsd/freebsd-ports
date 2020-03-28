libpm.c:836:12: warning: implicit declaration of function 'arc4random' is invalid in C99
      [-Wimplicit-function-declaration]
          return arc4random();
                     ^

--- lib/libpm.c.orig	2020-03-27 19:09:35 UTC
+++ lib/libpm.c
@@ -9,7 +9,7 @@
 **************************************************************************/
 
 #define _DEFAULT_SOURCE      /* New name for SVID & BSD source defines */
-#define _XOPEN_SOURCE 500    /* Make sure ftello, fseeko are defined */
+#define _BSD_SOURCE 1
 
 #include "netpbm/pm_config.h"
 
@@ -17,6 +17,7 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <stdarg.h>
+#include <stdlib.h>
 #include <string.h>
 #include <errno.h>
 #include <setjmp.h>
@@ -832,7 +833,7 @@ pm_arg0toprogname(const char arg0[]) {
 unsigned int
 pm_randseed(void) {
 
-    return time(NULL) ^ getpid();
+    return arc4random();
 
 }
 
