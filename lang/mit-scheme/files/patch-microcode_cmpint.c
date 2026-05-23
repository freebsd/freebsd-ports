--- microcode/cmpint.c.orig	2022-09-07 06:01:33 UTC
+++ microcode/cmpint.c
@@ -562,10 +562,10 @@ open_stack_gap (unsigned long offset, unsigned long n_
 {
   SCHEME_OBJECT * scan_from = (STACK_LOC (0));
   SCHEME_OBJECT * scan_end = (STACK_LOC (offset));
-  SCHEME_OBJECT * scan_to = (STACK_LOC (-n_words));
+  SCHEME_OBJECT * scan_to = (STACK_NEG (n_words));
   while (scan_from != scan_end)
     (STACK_LOCATIVE_POP (scan_to)) = (STACK_LOCATIVE_POP (scan_from));
-  stack_pointer = (STACK_LOC (-n_words));
+  stack_pointer = (STACK_NEG (n_words));
 }
 
 static void
@@ -2721,7 +2721,7 @@ bkpt_proceed (insn_t * ep, SCHEME_OBJECT handle, SCHEM
 	 && ((CC_RETURN_ADDRESS (STACK_REF (BKPT_PROCEED_FRAME_SIZE))) == ep)))
     error_external_return ();
   PUSH_REFLECTION (REFLECT_CODE_CC_BKPT);
-  stack_pointer = (STACK_LOC (-BKPT_PROCEED_FRAME_SIZE));
+  stack_pointer = (STACK_NEG (BKPT_PROCEED_FRAME_SIZE));
   return (SHARP_F);
 }
 
