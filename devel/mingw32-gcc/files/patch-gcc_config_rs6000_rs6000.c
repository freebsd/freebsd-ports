--- gcc/config/rs6000/rs6000.c.orig	2013-05-10 01:54:06 UTC
+++ gcc/config/rs6000/rs6000.c
@@ -9227,8 +9227,8 @@ rs6000_va_start (tree valist, rtx nextar
 	       FP_ARG_NUM_REG);
 
   if (TARGET_DEBUG_ARG)
-    fprintf (stderr, "va_start: words = "HOST_WIDE_INT_PRINT_DEC", n_gpr = "
-	     HOST_WIDE_INT_PRINT_DEC", n_fpr = "HOST_WIDE_INT_PRINT_DEC"\n",
+    fprintf (stderr, "va_start: words = " HOST_WIDE_INT_PRINT_DEC ", n_gpr = "
+	     HOST_WIDE_INT_PRINT_DEC ", n_fpr = " HOST_WIDE_INT_PRINT_DEC "\n",
 	     words, n_gpr, n_fpr);
 
   if (cfun->va_list_gpr_size)
@@ -18344,11 +18344,11 @@ debug_stack_info (rs6000_stack_t *info)
     fprintf (stderr, "\tvarargs_save_offset = %5d\n", info->varargs_save_offset);
 
   if (info->total_size)
-    fprintf (stderr, "\ttotal_size          = "HOST_WIDE_INT_PRINT_DEC"\n",
+    fprintf (stderr, "\ttotal_size          = " HOST_WIDE_INT_PRINT_DEC "\n",
 	     info->total_size);
 
   if (info->vars_size)
-    fprintf (stderr, "\tvars_size           = "HOST_WIDE_INT_PRINT_DEC"\n",
+    fprintf (stderr, "\tvars_size           = " HOST_WIDE_INT_PRINT_DEC "\n",
 	     info->vars_size);
 
   if (info->parm_size)
