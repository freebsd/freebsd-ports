--- float.c.orig	2010-09-13 18:43:04 UTC
+++ float.c
@@ -159,7 +159,7 @@ static ficlInteger ficlFloatStackDisplay
 {
     struct stackContext *context = (struct stackContext *)c;
     char buffer[64];
-    sprintf(buffer, "[0x%08x %3d] %16f (0x%08x)\n", cell, context->count++, (double)(cell->f), cell->i);
+    sprintf(buffer, "[0x%08lx %3d] %16f (0x%08lx)\n", (long unsigned)cell, context->count++, (double)(cell->f), (long)cell->i);
     ficlVmTextOut(context->vm, buffer);
 	return FICL_TRUE;
 }
