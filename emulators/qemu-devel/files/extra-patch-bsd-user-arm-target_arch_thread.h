diff --git a/bsd-user/arm/target_arch_thread.h b/bsd-user/arm/target_arch_thread.h
index e69f612..ee4d67d 100644
--- a/bsd-user/arm/target_arch_thread.h
+++ b/bsd-user/arm/target_arch_thread.h
@@ -29,8 +29,8 @@ static inline void target_thread_set_upcall(CPUARMState *regs, abi_ulong entry,
      * Make sure the stack is properly aligned.
      * arm/include/param.h (STACKLIGN() macro)
      */
-    sp = ((u_int)(stack_base + stack_size) & ~(8-1)) -
-        sizeof(struct target_trapframe);
+    sp = (u_int)((stack_base + stack_size) -
+        sizeof(struct target_trapframe)) & ~0x7;
 
     /* sp = stack base */
     regs->regs[13] = sp;
