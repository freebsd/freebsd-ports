--- a/cpu-exec.c
+++ b/cpu-exec.c
@@ -681,6 +681,10 @@ int cpu_exec(CPUArchState *env)
              * local variables as longjmp is marked 'noreturn'. */
             cpu = current_cpu;
             env = cpu->env_ptr;
+#if !(defined(CONFIG_USER_ONLY) && \
+      (defined(TARGET_M68K) || defined(TARGET_PPC) || defined(TARGET_S390X)))
+            cc = CPU_GET_CLASS(cpu);
+#endif
         }
     } /* for(;;) */
 
