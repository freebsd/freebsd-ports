--- src/exec.c.orig	Sun Aug 15 19:57:08 2004
+++ src/exec.c	Sun Aug 15 19:57:55 2004
@@ -108,6 +108,7 @@
   { 47031, 47031, 47031}  //15 or
 };
 
+void exec_execute_proc(struct s_proc *proc);
 
 /**
    main execution function.<br>
