--- primitives.c.orig	2010-09-13 18:43:04 UTC
+++ primitives.c
@@ -487,7 +487,7 @@ static void ficlPrimitiveSprintf(ficlVm 
 
 	ficlStackPushPointer(vm->dataStack, bufferStart);
 	ficlStackPushInteger(vm->dataStack, buffer - bufferStart);
-	ficlStackPushInteger(vm->dataStack, append && FICL_TRUE);
+	ficlStackPushInteger(vm->dataStack, FICL_BOOL(!append));
 }
 
 
@@ -1350,7 +1350,7 @@ static void ficlPrimitiveSetObjectFlag(f
 
 static void ficlPrimitiveIsObject(ficlVm *vm)
 {
-    int flag;
+    ficlInteger flag;
     ficlWord *word = (ficlWord *)ficlStackPopPointer(vm->dataStack);
     
     flag = ((word != NULL) && (word->flags & FICL_WORD_OBJECT)) ? FICL_TRUE : FICL_FALSE;
