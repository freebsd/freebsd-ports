--- birnet/birnetcpu.cc.orig	2008-02-26 23:19:28.000000000 +0100
+++ birnet/birnetcpu.cc	2008-02-26 23:25:30.000000000 +0100
@@ -201,7 +201,7 @@
       struct sigaction action, old_action;
       action.sa_handler = cpu_info_sigill_handler;
       sigemptyset (&action.sa_mask);
-      action.sa_flags = SA_NOMASK;
+      action.sa_flags = SA_NODEFER;
       sigaction (SIGILL, &action, &old_action);
       if (setjmp (cpu_info_jmp_buf) == 0)
         {
