--- qemu.orig/cpu-exec.c	Mon Jan 14 11:11:02 2008
+++ qemu/cpu-exec.c	Thu Jan 17 23:03:00 2008
@@ -449,16 +449,18 @@ int cpu_exec(CPUState *env1)
                         (env->eflags & IF_MASK || env->hflags & HF_HIF_MASK) &&
                         !(env->hflags & HF_INHIBIT_IRQ_MASK)) {
                         int intno;
-                        svm_check_intercept(SVM_EXIT_INTR);
                         env->interrupt_request &= ~(CPU_INTERRUPT_HARD | CPU_INTERRUPT_VIRQ);
                         intno = cpu_get_pic_interrupt(env);
-                        if (loglevel & CPU_LOG_TB_IN_ASM) {
-                            fprintf(logfile, "Servicing hardware INT=0x%02x\n", intno);
-                        }
-                        do_interrupt(intno, 0, 0, 0, 1);
-                        /* ensure that no TB jump will be modified as
-                           the program flow was changed */
-                        BREAK_CHAIN;
+	                     if(intno>=0) {
+                            svm_check_intercept(SVM_EXIT_INTR);
+                            if (loglevel & CPU_LOG_TB_IN_ASM) {
+                                fprintf(logfile, "Servicing hardware INT=0x%02x\n", intno);
+                            }
+                            do_interrupt(intno, 0, 0, 0, 1);
+                           /* ensure that no TB jump will be modified as
+                              the program flow was changed */
+                            BREAK_CHAIN;
+                        }
 #if !defined(CONFIG_USER_ONLY)
                     } else if ((interrupt_request & CPU_INTERRUPT_VIRQ) &&
                         (env->eflags & IF_MASK) && !(env->hflags & HF_INHIBIT_IRQ_MASK)) {
