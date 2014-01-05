--- primitives.c.orig	2014-01-05 15:25:11.000000000 +0400
+++ primitives.c	2014-01-05 16:00:30.000000000 +0400
@@ -487,7 +487,7 @@
 
 	ficlStackPushPointer(vm->dataStack, bufferStart);
 	ficlStackPushInteger(vm->dataStack, buffer - bufferStart);
-	ficlStackPushInteger(vm->dataStack, append && FICL_TRUE);
+	ficlStackPushInteger(vm->dataStack, FICL_BOOL(!append));
 }
 
 
@@ -1350,7 +1350,7 @@
 
 static void ficlPrimitiveIsObject(ficlVm *vm)
 {
-    int flag;
+    ficlInteger flag;
     ficlWord *word = (ficlWord *)ficlStackPopPointer(vm->dataStack);
     
     flag = ((word != NULL) && (word->flags & FICL_WORD_OBJECT)) ? FICL_TRUE : FICL_FALSE;
