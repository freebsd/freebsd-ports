--- MyErrorsHandlers.c.orig	Wed Jan  7 11:29:34 2004
+++ MyErrorsHandlers.c	Thu Jan  8 23:36:16 2004
@@ -3,7 +3,7 @@
 #include <stdio.h>
 #include <signal.h>
 #include <stdlib.h>
-#include <wait.h>
+#include <sys/wait.h>
 
 #include "wbx.h"
 #include "py.h"
