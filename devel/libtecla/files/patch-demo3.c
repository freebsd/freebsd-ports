--- demo3.c.orig	Sat Aug 12 19:31:16 2006
+++ demo3.c	Sat Aug 12 19:31:29 2006
@@ -37,17 +37,17 @@
 #include <locale.h>
 #include <setjmp.h>
 
-#ifdef HAVE_SELECT
-#ifdef HAVE_SYS_SELECT_H
-#include <sys/select.h>
-#endif
-#endif
-
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/time.h>    
 #include <sys/types.h>
 #include <signal.h>
+
+#ifdef HAVE_SELECT
+#ifdef HAVE_SYS_SELECT_H
+#include <sys/select.h>
+#endif
+#endif
 
 #include "libtecla.h"
 
