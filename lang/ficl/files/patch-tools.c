--- tools.c.orig	2010-08-12 13:57:22 UTC
+++ tools.c
@@ -236,24 +236,24 @@ static void ficlPrimitiveSeeXT(ficlVm *v
         break;
 
     case FICL_WORDKIND_VARIABLE:
-        sprintf(vm->pad, "variable = %ld (%#lx)\n", word->param->i, word->param->u);
+        sprintf(vm->pad, "variable = %ld (%#lx)\n", (long)word->param->i, (long unsigned)word->param->u);
         ficlVmTextOut(vm, vm->pad);
         break;
 
 #if FICL_WANT_USER
     case FICL_WORDKIND_USER:
-        sprintf(vm->pad, "user variable %ld (%#lx)\n", word->param->i, word->param->u);
+        sprintf(vm->pad, "user variable %ld (%#lx)\n", (long)word->param->i, (long unsigned)word->param->u);
         ficlVmTextOut(vm, vm->pad);
         break;
 #endif
 
     case FICL_WORDKIND_CONSTANT:
-        sprintf(vm->pad, "constant = %ld (%#lx)\n", word->param->i, word->param->u);
+        sprintf(vm->pad, "constant = %ld (%#lx)\n", (long)word->param->i, (long unsigned)word->param->u);
         ficlVmTextOut(vm, vm->pad);
 		break;
 
     case FICL_WORDKIND_2CONSTANT:
-        sprintf(vm->pad, "constant = %ld %ld (%#lx %#lx)\n", word->param[1].i, word->param->i, word->param[1].u, word->param->u);
+        sprintf(vm->pad, "constant = %ld %ld (%#lx %#lx)\n", (long)word->param[1].i, (long)word->param->i, (long unsigned)word->param[1].u, (long unsigned)word->param->u);
         ficlVmTextOut(vm, vm->pad);
 		break;
 
@@ -567,7 +567,7 @@ static ficlInteger ficlStackDisplayCallb
 {
     struct stackContext *context = (struct stackContext *)c;
     char buffer[64];
-    sprintf(buffer, "[0x%08x %3d]: %12d (0x%08x)\n", cell, context->count++, cell->i, cell->i);
+    sprintf(buffer, "[0x%08lx %3d]: %12ld (0x%08lx)\n", (long unsigned)cell, context->count++, (long)cell->i, (long unsigned)cell->u); /* Did it should be cell->i, not cell->u? */
 	ficlVmTextOut(context->vm, buffer);
 	return FICL_TRUE;
 }
@@ -580,7 +580,7 @@ void ficlStackDisplay(ficlStack *stack, 
 
     FICL_STACK_CHECK(stack, 0, 0);
 
-	sprintf(buffer, "[%s stack has %d entries, top at 0x%08x]\n", stack->name, ficlStackDepth(stack), stack->top);
+	sprintf(buffer, "[%s stack has %d entries, top at 0x%08lx]\n", stack->name, ficlStackDepth(stack), (long unsigned)stack->top);
 	ficlVmTextOut(vm, buffer);
 
     if (callback == NULL)
@@ -592,7 +592,7 @@ void ficlStackDisplay(ficlStack *stack, 
     }
 	ficlStackWalk(stack, callback, context, FICL_FALSE);
 
-	sprintf(buffer, "[%s stack base at 0x%08x]\n", stack->name, stack->base);
+	sprintf(buffer, "[%s stack base at 0x%08lx]\n", stack->name, (long unsigned)stack->base);
 	ficlVmTextOut(vm, buffer);
 
     return;
@@ -612,7 +612,7 @@ static ficlInteger ficlStackDisplaySimpl
 {
     struct stackContext *context = (struct stackContext *)c;
     char buffer[32];
-    sprintf(buffer, "%s%d", context->count ? " " : "", cell->i);
+    sprintf(buffer, "%s%ld", context->count ? " " : "", (long)cell->i);
     context->count++;
     ficlVmTextOut(context->vm, buffer);
 	return FICL_TRUE;
@@ -644,7 +644,7 @@ static ficlInteger ficlReturnStackDispla
     struct stackContext *context = (struct stackContext *)c;
     char buffer[128];
 
-    sprintf(buffer, "[0x%08x %3d] %12d (0x%08x)", cell, context->count++, cell->i, cell->i);
+    sprintf(buffer, "[0x%08lx %3d] %12ld (0x%08lx)", (long unsigned)cell, context->count++, (long)cell->i, (long unsigned)cell->u); /* Did it should be cell->i, not cell->u? */
 
     /*
     ** Attempt to find the word that contains the return
