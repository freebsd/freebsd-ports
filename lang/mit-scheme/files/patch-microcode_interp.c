--- microcode/interp.c.orig	2022-09-07 06:01:33 UTC
+++ microcode/interp.c
@@ -455,7 +455,7 @@ Interpret (void)
       {
 	long length = ((VECTOR_LENGTH (GET_EXP)) - 1);
 	Will_Push (length + 2 + CONTINUATION_SIZE);
-	stack_pointer = (STACK_LOC (-length));
+	stack_pointer = (STACK_NEG (length));
         STACK_PUSH (MAKE_OBJECT (TC_MANIFEST_NM_VECTOR, length));
 	/* The finger: last argument number */
 	Pushed ();
@@ -1156,7 +1156,7 @@ Interpret (void)
       /* Frame consists of the return code followed by two objects.
 	 The first object has already been popped into GET_EXP,
          so just pop the second argument.  */
-      stack_pointer = (STACK_LOCATIVE_OFFSET (stack_pointer, 1));
+      stack_pointer = (STACK_LOCATIVE_ADD (stack_pointer, 1));
       break;
 
     case RC_EXECUTE_SEQUENCE_FINISH:
