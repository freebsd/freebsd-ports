--- lisp-kernel/threads.h.orig	2020-04-19 21:32:56 UTC
+++ lisp-kernel/threads.h
@@ -187,7 +187,7 @@ void tsd_set(LispObj, void *);
 void *tsd_get(LispObj);
 TCR *new_tcr(natural, natural);
 void thread_init_tcr(TCR *tcr, void *stack_base, natural stack_size);
-TCR *initial_thread_tcr;
+extern TCR *initial_thread_tcr;
 
 #define DEFAULT_THREAD_STACK_SIZE ((size_t) -1)
 #define MINIMAL_THREAD_STACK_SIZE ((size_t) 0)
