--- microcode/step.c.orig	2022-09-07 06:01:33 UTC
+++ microcode/step.c
@@ -103,7 +103,7 @@ DEFINE_PRIMITIVE ("PRIMITIVE-APPLY-STEP", Prim_apply_s
       POP_PRIMITIVE_FRAME (3);
       install_traps (hooks);
       {
-	SCHEME_OBJECT * scan_stack = (STACK_LOC (- number_of_args));
+	SCHEME_OBJECT * scan_stack = (STACK_NEG (number_of_args));
 	SCHEME_OBJECT scan_list;
 	long i;
 	Will_Push (number_of_args + STACK_ENV_EXTRA_SLOTS + 1);
