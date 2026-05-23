--- microcode/hooks.c.orig	2022-09-07 06:01:33 UTC
+++ microcode/hooks.c
@@ -37,7 +37,7 @@ static void with_new_interrupt_mask (unsigned long);
 
 /* This is a kludge to compensate for the interpreter popping
    a primitive's frame off the stack after it returns.  */
-#define UN_POP_PRIMITIVE_FRAME(n) (stack_pointer = (STACK_LOC (-(n))))
+#define UN_POP_PRIMITIVE_FRAME(n) (stack_pointer = (STACK_NEG (n)))
 
 DEFINE_PRIMITIVE ("APPLY", Prim_apply, 2, 2, "(PROCEDURE ARG-LIST)\n\
 Invokes PROCEDURE on the arguments in ARG-LIST.")
@@ -87,7 +87,7 @@ Invokes PROCEDURE on the arguments in ARG-LIST.")
 
     {
       SCHEME_OBJECT p1 = args;
-      SCHEME_OBJECT * sp = (STACK_LOC (-n_args));
+      SCHEME_OBJECT * sp = (STACK_NEG (n_args));
       SCHEME_OBJECT * s1 = sp;
       while (s1 != stack_pointer)
 	{
