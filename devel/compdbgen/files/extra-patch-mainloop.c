--- mainloop.c.orig	2025-09-11 04:56:11 UTC
+++ mainloop.c
@@ -433,20 +433,32 @@ static void enter_syscall(struct glbctx *info, struct 
   static int json_item_cnt = 0;
   struct syscall *sc;
   u_int i, narg;
+#if defined(__FreeBSD_version) && __FreeBSD_version < 1400000
+  register_t *args;
+#else
   syscallarg_t *args;
+#endif
 
   /* ignore other syscall except execve */
   if (pl->pl_syscall_code != SYS_execve) {
     return;
   }
 
+#if defined(__FreeBSD_version) && __FreeBSD_version < 1400000
+  args = calloc(pl->pl_syscall_narg, sizeof(register_t));
+#else
   args = calloc(pl->pl_syscall_narg, sizeof(syscallarg_t));
+#endif
   if (args == NULL) {
     err(1, "malloc syscall args failed\n");
   }
 
   if (ptrace(PT_GET_SC_ARGS, t->tid, (caddr_t)args,
+#if defined(__FreeBSD_version) && __FreeBSD_version < 1400000
+             sizeof(register_t) * pl->pl_syscall_narg) != 0) {
+#else
              sizeof(syscallarg_t) * pl->pl_syscall_narg) != 0) {
+#endif
     goto _EXIT;
   }
 
