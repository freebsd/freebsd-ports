--- process.c.orig	2000-06-01 22:30:18.000000000 +0300
+++ process.c	2009-03-03 17:37:30.000000000 +0200
@@ -38,6 +38,7 @@
 
 #define SCM_PROCESS(x)		((SCM_ProcessAux*)SCM_AUX(x))
 #define SCM_PROCESSP(x)		(SCM_OBJTYPE(x) == SOBJ_T_PROCESS)
+#define SCM_PROCESS_SET		SCM_AUX_SET
 
 #define SCM_PROCESS_PID(x)		(SCM_PROCESS(x)->pid)
 #define SCM_PROCESS_PORT(x,i) 	(SCM_PROCESS(x)->port[i])
@@ -153,7 +154,8 @@
   int i;
   SOBJ new = scm_newcell(SOBJ_T_PROCESS);
 
-  SCM_PROCESS(new) = scm_must_alloc(sizeof(SCM_ProcessAux));
+  /*SCM_PROCESS_SET(new) = scm_must_alloc(sizeof(SCM_ProcessAux));*/
+  SCM_PROCESS_SET(new, scm_must_alloc(sizeof(SCM_ProcessAux)));
   SCM_PROCESS_PID(new) = 0;
   for (i = 0; i < 3; i++)
     SCM_PROCESS_PORT(new, i) = NULL;
