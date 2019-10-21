--- runtime/flangrti/trace_lin.c.orig	2019-10-09 20:28:35 UTC
+++ runtime/flangrti/trace_lin.c
@@ -25,7 +25,7 @@
 #include <string.h>
 #include <sys/types.h>
 #include <unistd.h>
-#include <linux/limits.h>
+#include <limits.h>
 #include <inttypes.h>
 
 /* codes and strings for signals */
@@ -92,7 +92,7 @@ static struct sigs sigs[] = {
     {0, CODNULL, NULL} /* end of list */
 };
 
-static gregset_t *regs; /* pointer to regs at signal  */
+static void *regs; /* pointer to regs at signal  */
 
 extern char **__io_get_argv();
 static char ** saved_argv = NULL;
@@ -182,7 +182,7 @@ __abort_trace(int skip)
   char **strings;
   size_t i;
 
-  if (regs != (gregset_t *)0) {
+  if (regs != (void *)0) {
     dumpregs(regs);
   }
 
