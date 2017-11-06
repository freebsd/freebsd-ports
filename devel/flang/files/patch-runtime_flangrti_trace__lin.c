--- runtime/flangrti/trace_lin.c.orig	2017-10-19 11:03:03 UTC
+++ runtime/flangrti/trace_lin.c
@@ -85,7 +85,7 @@ static struct sigs sigs[] = {
     {0, CODNULL, NULL} /* end of list */
 };
 
-static gregset_t *regs; /* pointer to regs at signal  */
+static void *regs; /* pointer to regs at signal  */
 
 /* walk the stack back */
 
@@ -99,7 +99,7 @@ __abort_trace(int skip)
   char **strings;
   size_t i;
 
-  if (regs != (gregset_t *)0) {
+  if (regs != (void *)0) {
     dumpregs(regs);
   }
 
