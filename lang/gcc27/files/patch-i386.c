--- config/i386/i386.c.orig	Sun Oct 22 04:13:21 1995
+++ config/i386/i386.c	Mon Mar 20 13:29:12 2000
@@ -1460,7 +1460,8 @@
   int limit;
   rtx xops[4];
   int pic_reg_used = flag_pic && (current_function_uses_pic_offset_table
-				  || current_function_uses_const_pool);
+				  || current_function_uses_const_pool
+				  || profile_flag || profile_block_flag);
 
   xops[0] = stack_pointer_rtx;
   xops[1] = frame_pointer_rtx;
@@ -1521,8 +1522,16 @@
   int nregs = 0;
   int reglimit = (frame_pointer_needed
 		  ? FRAME_POINTER_REGNUM : STACK_POINTER_REGNUM);
-  int pic_reg_used = flag_pic && (current_function_uses_pic_offset_table
-				  || current_function_uses_const_pool);
+
+#ifdef FUNCTION_PROFILER_EPILOGUE
+  if (profile_flag)
+    return 0;
+#endif
+
+  if (flag_pic && (current_function_uses_pic_offset_table
+		   || current_function_uses_const_pool
+		   || profile_flag || profile_block_flag))
+    return 0;
 
 #ifdef NON_SAVING_SETJMP
   if (NON_SAVING_SETJMP && current_function_calls_setjmp)
@@ -1533,8 +1542,7 @@
     return 0;
 
   for (regno = reglimit - 1; regno >= 0; regno--)
-    if ((regs_ever_live[regno] && ! call_used_regs[regno])
-	|| (regno == PIC_OFFSET_TABLE_REGNUM && pic_reg_used))
+    if (regs_ever_live[regno] && ! call_used_regs[regno])
       nregs++;
 
   return nregs == 0 || ! frame_pointer_needed;
@@ -1557,6 +1565,11 @@
   int pic_reg_used = flag_pic && (current_function_uses_pic_offset_table
 				  || current_function_uses_const_pool);
 
+#ifdef FUNCTION_PROFILER_EPILOGUE
+  if (profile_flag)
+    FUNCTION_PROFILER_EPILOGUE (file);
+#endif
+
   /* Compute the number of registers to pop */
 
   limit = (frame_pointer_needed
@@ -2438,7 +2451,7 @@
       REAL_VALUE_FROM_CONST_DOUBLE (r, x);
       REAL_VALUE_TO_TARGET_SINGLE (r, l);
       PRINT_IMMED_PREFIX (file);
-      fprintf (file, "0x%x", l);
+      fprintf (file, "0x%lx", l);
     }
  /* These float cases don't actually occur as immediate operands. */
  else if (GET_CODE (x) == CONST_DOUBLE && GET_MODE (x) == DFmode)
