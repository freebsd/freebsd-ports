--- a/bsd-user/main.c
+++ b/bsd-user/main.c
@@ -129,7 +129,7 @@ static int pending_cpus;
 /* Make sure everything is in a consistent state for calling fork(). */
 void fork_start(void)
 {
-	spin_lock(&tb_lock);
+	spin_lock(&tcg_ctx.tb_ctx.tb_lock);
 	pthread_mutex_lock(&exclusive_lock);
 	mmap_fork_start();
 }
@@ -149,11 +149,11 @@ void fork_end(int child)
 		pthread_mutex_init(&cpu_list_mutex, NULL);
 		pthread_cond_init(&exclusive_cond, NULL);
 		pthread_cond_init(&exclusive_resume, NULL);
-		spin_lock_init(&tb_lock);
+		spin_lock_init(&tcg_ctx.tb_ctx.tb_lock);
 		gdbserver_fork(thread_env);
 	} else {
 		pthread_mutex_unlock(&exclusive_lock);
-		spin_unlock(&tb_lock);
+		spin_unlock(&tcg_ctx.tb_ctx.tb_lock);
 	}
 }
 
@@ -174,6 +174,7 @@ static inline void
 start_exclusive(void)
 {
 	CPUArchState *other;
+	CPUState *other_cpu;
 
 	pthread_mutex_lock(&exclusive_lock);
 	exclusive_idle();
@@ -181,7 +182,8 @@ start_exclusive(void)
 	pending_cpus = 1;
 	/* Make all other cpus stop executing. */
 	for (other = first_cpu; other; other = other->next_cpu) {
-		if (other->running) {
+		other_cpu = ENV_GET_CPU(other);
+		if (other_cpu->running) {
 			pending_cpus++;
 			cpu_exit(other);
 		}
@@ -202,20 +204,20 @@ end_exclusive(void)
 
 /* Wait for exclusive ops to finish, and begin cpu execution. */
 static inline void
-cpu_exec_start(CPUArchState *env)
+cpu_exec_start(CPUState *cpu)
 {
 	pthread_mutex_lock(&exclusive_lock);
 	exclusive_idle();
-	env->running = 1;
+	cpu->running = true;
 	pthread_mutex_unlock(&exclusive_lock);
 }
 
 /* Mark cpu as not excuting, and release pending exclusive ops. */
 static inline void
-cpu_exec_end(CPUArchState *env)
+cpu_exec_end(CPUState *cpu)
 {
 	pthread_mutex_lock(&exclusive_lock);
-	env->running = 0;
+	cpu->running = false;
 	if (pending_cpus > 1) {
 		pending_cpus--;
 		if (pending_cpus == 1) {
@@ -270,13 +272,13 @@ end_exclusive(void)
 }
 
 static inline void
-cpu_exec_start(CPUArchState *env)
+cpu_exec_start(CPUState *cpu)
 {
 }
 
 
 static inline void
-cpu_exec_end(CPUArchState *env)
+cpu_exec_end(CPUState *cpu)
 {
 }
 
@@ -657,6 +659,7 @@ done:
 
 void cpu_loop(CPUARMState *env)
 {
+    CPUState *cs = CPU(arm_env_get_cpu(env));
     int trapnr;
     unsigned int n, insn;
     uint32_t addr;
@@ -665,7 +668,7 @@ void cpu_loop(CPUARMState *env)
 #ifdef DEBUG_ARM
 	printf("CPU LOOPING\n");
 #endif
-        cpu_exec_start(env);
+        cpu_exec_start(cs);
 #ifdef DEBUG_ARM
 	printf("EXECUTING...\n");
 #endif
@@ -673,7 +676,7 @@ void cpu_loop(CPUARMState *env)
 #ifdef DEBUG_ARM
 	printf("trapnr %d\n", trapnr);
 #endif
-        cpu_exec_end(env);
+        cpu_exec_end(cs);
         switch(trapnr) {
         case EXCP_UDEF:
             {
@@ -1008,15 +1011,16 @@ static int do_store_exclusive(CPUMIPSSta
 
 void cpu_loop(CPUMIPSState *env)
 {
+	CPUState *cs = CPU(mips_env_get_cpu(env));
 	target_siginfo_t info;
 	int trapnr;
 	abi_long ret;
 	unsigned int syscall_num;
 
 	for(;;) {
-		cpu_exec_start(env);
+		cpu_exec_start(cs);
 		trapnr = cpu_mips_exec(env);
-		cpu_exec_end(env);
+		cpu_exec_end(cs);
 		switch(trapnr) {
 		case EXCP_SYSCALL: /* syscall exception */
 			syscall_num = env->active_tc.gpr[2]; /* v0 */
