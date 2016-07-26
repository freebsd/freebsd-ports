--- birnet/birnetcpu.cc.orig	2013-01-19 00:23:42 UTC
+++ birnet/birnetcpu.cc
@@ -174,7 +174,7 @@ get_x86_cpu_features (CPUInfo *ci,
       struct sigaction action, old_action;
       action.sa_handler = cpu_info_sigill_handler;
       sigemptyset (&action.sa_mask);
-      action.sa_flags = SA_NOMASK;
+      action.sa_flags = SA_NODEFER;
       sigaction (SIGILL, &action, &old_action);
       if (setjmp (cpu_info_jmp_buf) == 0)
         {
