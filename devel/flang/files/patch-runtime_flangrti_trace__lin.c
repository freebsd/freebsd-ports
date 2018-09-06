--- runtime/flangrti/trace_lin.c.orig	2018-09-03 06:03:48 UTC
+++ runtime/flangrti/trace_lin.c
@@ -87,7 +87,7 @@ static struct sigs sigs[] = {
     {0, CODNULL, NULL} /* end of list */
 };
 
-static gregset_t *regs; /* pointer to regs at signal  */
+static void *regs; /* pointer to regs at signal  */
 
 extern char **__io_get_argv();
 static char ** saved_argv;
@@ -143,7 +143,7 @@ __abort_trace(int skip)
   char **strings;
   size_t i;
 
-  if (regs != (gregset_t *)0) {
+  if (regs != (void *)0) {
     dumpregs(regs);
   }
 
