--- emit-rtl.c.orig	Thu Sep 14 13:09:30 1995
+++ emit-rtl.c	Mon Mar 20 13:29:11 2000
@@ -159,6 +159,10 @@
 rtx static_chain_incoming_rtx;	/* (REG:Pmode STATIC_CHAIN_INCOMING_REGNUM) */
 rtx pic_offset_table_rtx;	/* (REG:Pmode PIC_OFFSET_TABLE_REGNUM) */
 
+/* This is used to implement __builtin_return_address for some machines.
+   See for instance the MIPS port.  */
+rtx return_address_pointer_rtx; /* (REG:Pmode RETURN_ADDRESS_POINTER_REGNUM) */
+
 rtx virtual_incoming_args_rtx;	/* (REG:Pmode VIRTUAL_INCOMING_ARGS_REGNUM) */
 rtx virtual_stack_vars_rtx;	/* (REG:Pmode VIRTUAL_STACK_VARS_REGNUM) */
 rtx virtual_stack_dynamic_rtx;	/* (REG:Pmode VIRTUAL_STACK_DYNAMIC_REGNUM) */
@@ -345,6 +349,11 @@
 	  && ! reload_in_progress)
 	return arg_pointer_rtx;
 #endif
+#ifdef RETURN_ADDRESS_POINTER_REGNUM
+      if (return_address_pointer_rtx && regno == RETURN_ADDRESS_POINTER_REGNUM
+	  && mode == Pmode && ! reload_in_progress)
+	return return_address_pointer_rtx;
+#endif
       if (stack_pointer_rtx && regno == STACK_POINTER_REGNUM && mode == Pmode
 	  && ! reload_in_progress)
 	return stack_pointer_rtx;
@@ -3391,6 +3400,11 @@
     arg_pointer_rtx = stack_pointer_rtx;
   else
     arg_pointer_rtx = gen_rtx (REG, Pmode, ARG_POINTER_REGNUM);
+
+#ifdef RETURN_ADDRESS_POINTER_REGNUM
+  return_address_pointer_rtx = gen_rtx (REG, Pmode,
+					RETURN_ADDRESS_POINTER_REGNUM);
+#endif
 
   /* Create the virtual registers.  Do so here since the following objects
      might reference them.  */
