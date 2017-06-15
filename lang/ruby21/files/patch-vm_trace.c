--- vm_trace.c.orig	2015-11-18 12:26:40.000000000 +0100
+++ vm_trace.c	2016-01-10 18:54:08.421021000 +0100
@@ -392,7 +392,7 @@ rb_suppress_tracing(VALUE (*func)(VALUE)
     volatile int raised;
     volatile int outer_state;
     VALUE result = Qnil;
-    rb_thread_t *th = GET_THREAD();
+    rb_thread_t *volatile th = GET_THREAD();
     int state;
     const int tracing = th->trace_arg ? 1 : 0;
     rb_trace_arg_t dummy_trace_arg;
