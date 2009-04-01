--- sproto.h.orig	2000-06-23 03:10:23.000000000 +0400
+++ sproto.h	2009-04-01 20:17:48.000000000 +0400
@@ -619,7 +619,7 @@
 void scm_dump_env (SOBJ e );
 void scm_vmfunc_mark (SOBJ obj );
 void scm_vmfunc_sweep (SOBJ obj );
-inline void scm_vm_move_stack (SOBJ *dst , SOBJ *src , int nitems );
+void scm_vm_move_stack (SOBJ *dst , SOBJ *src , int nitems );
 void scm_vm (SCM_VMD *vm );
 void scm_engine_init PROTO ((void));
 SOBJ scm_run_engine (SOBJ *ip );
