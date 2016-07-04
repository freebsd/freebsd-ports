--- src/racket/src/future.c.orig	2016-04-15 20:33:56 UTC
+++ src/racket/src/future.c
@@ -184,6 +184,11 @@ Scheme_Object *scheme_make_fsemaphore(in
   return (Scheme_Object*)fsema;
 }
 
+static Scheme_Object *make_fsemaphore(int argc, Scheme_Object *argv[])
+{
+  return scheme_make_fsemaphore(argc, argv);
+}
+
 Scheme_Object *scheme_fsemaphore_post(int argc, Scheme_Object *argv[])
 {
   fsemaphore_t *fsema;
@@ -247,46 +252,24 @@ static Scheme_Object *mark_future_trace_
   return scheme_void;
 }
 
-# define FUTURE_PRIM_W_ARITY(name, func, a1, a2, env) GLOBAL_PRIM_W_ARITY(name, func, a1, a2, env)
-
-void scheme_init_futures(Scheme_Env *newenv)
-{
-  FUTURE_PRIM_W_ARITY("future?",          future_p,         1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("future",           scheme_future,    1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("processor-count",  processor_count,  0, 0, newenv);
-  FUTURE_PRIM_W_ARITY("touch",            touch,            1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("current-future",   scheme_current_future,   0, 0, newenv);
-  FUTURE_PRIM_W_ARITY("make-fsemaphore",  scheme_make_fsemaphore,  1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("fsemaphore?",      scheme_fsemaphore_p,     1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("fsemaphore-post",  scheme_fsemaphore_post,  1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("fsemaphore-wait",  scheme_fsemaphore_wait,  1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("fsemaphore-try-wait?", scheme_fsemaphore_try_wait, 1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("fsemaphore-count", scheme_fsemaphore_count, 1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("would-be-future", would_be_future, 1, 1, newenv);
-  FUTURE_PRIM_W_ARITY("futures-enabled?", futures_enabled, 0, 0, newenv);
-  FUTURE_PRIM_W_ARITY("reset-future-logs-for-tracing!", reset_future_logs_for_tracking, 0, 0, newenv);
-  GLOBAL_PRIM_W_ARITY("mark-future-trace-end!", mark_future_trace_end, 0, 0, newenv);
-
-  scheme_finish_primitive_module(newenv);
-  scheme_protect_primitive_provide(newenv, NULL);
-
-#ifdef MZ_PRECISE_GC
-  register_traversers();
-#endif
-}
-
 void scheme_init_futures_once()
 {
 }
 
 void scheme_init_futures_per_place()
 {
+#ifdef MZ_PRECISE_GC
+  register_traversers();
+#endif
 }
 
 void scheme_end_futures_per_place()
 {
 }
 
+#define SCHEME_FUTURE_PRIM_IS_NARY_INLINED  SCHEME_PRIM_SOMETIMES_INLINED
+#define SCHEME_FUTURE_PRIM_IS_UNARY_INLINED SCHEME_PRIM_SOMETIMES_INLINED
+
 #else
 
 #include "future.h"
@@ -467,6 +450,11 @@ typedef struct future_thread_params_t {
   Scheme_Current_LWC *lwc;
 } future_thread_params_t;
 
+#define SCHEME_FUTURE_PRIM_IS_NARY_INLINED  SCHEME_PRIM_IS_NARY_INLINED
+#define SCHEME_FUTURE_PRIM_IS_UNARY_INLINED SCHEME_PRIM_IS_UNARY_INLINED
+
+#endif
+
 /**********************************************************************/
 /* Plumbing for Racket initialization                                 */
 /**********************************************************************/
@@ -476,6 +464,9 @@ void scheme_init_futures(Scheme_Env *new
 {
   Scheme_Object *p;
 
+  /* Order and properties here need to be in sync with the order and
+     properties in the other scheme_init_futures() */
+
   scheme_add_global_constant(
                              "future?", 
                              scheme_make_folding_prim(
@@ -487,7 +478,7 @@ void scheme_init_futures(Scheme_Env *new
                              newenv);
 
   p = scheme_make_prim_w_arity(scheme_future, "future", 1, 1);
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_UNARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_UNARY_INLINED);
   scheme_add_global_constant("future", p, newenv);
 
   scheme_add_global_constant(
@@ -500,7 +491,7 @@ void scheme_init_futures(Scheme_Env *new
                              newenv);
 
   p = scheme_make_prim_w_arity(touch, "touch", 1, 1);
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_UNARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_UNARY_INLINED);
   scheme_add_global_constant("touch", p, newenv);
 
   p = scheme_make_immed_prim( 
@@ -508,7 +499,7 @@ void scheme_init_futures(Scheme_Env *new
                               "current-future", 
                               0, 
                               0);
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_NARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_NARY_INLINED);
   scheme_add_global_constant("current-future", p, newenv);
 
   p = scheme_make_immed_prim(
@@ -517,7 +508,7 @@ void scheme_init_futures(Scheme_Env *new
                               1, 
                               1);
 
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_UNARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_UNARY_INLINED);
   scheme_add_global_constant("fsemaphore?", p, newenv);
 
   p = scheme_make_immed_prim(
@@ -525,7 +516,7 @@ void scheme_init_futures(Scheme_Env *new
                               "make-fsemaphore", 
                               1, 
                               1);
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_UNARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_UNARY_INLINED);
   scheme_add_global_constant("make-fsemaphore", p, newenv);
 
   p = scheme_make_immed_prim(
@@ -533,7 +524,7 @@ void scheme_init_futures(Scheme_Env *new
                               "fsemaphore-count", 
                               1, 
                               1);
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_UNARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_UNARY_INLINED);
   scheme_add_global_constant("fsemaphore-count", p, newenv);
   
   p = scheme_make_immed_prim(
@@ -541,7 +532,7 @@ void scheme_init_futures(Scheme_Env *new
                               "fsemaphore-wait",
                               1, 
                               1);
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_UNARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_UNARY_INLINED);
   scheme_add_global_constant("fsemaphore-wait", p, newenv);
 
   p = scheme_make_immed_prim(
@@ -549,7 +540,7 @@ void scheme_init_futures(Scheme_Env *new
                               "fsemaphore-post", 
                               1, 
                               1);
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_UNARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_UNARY_INLINED);
   scheme_add_global_constant("fsemaphore-post", p, newenv);
 
   p = scheme_make_immed_prim(
@@ -557,7 +548,7 @@ void scheme_init_futures(Scheme_Env *new
                               "fsemaphore-try-wait?", 
                               1, 
                               1);
-  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_PRIM_IS_UNARY_INLINED);
+  SCHEME_PRIM_PROC_FLAGS(p) |= scheme_intern_prim_opt_flags(SCHEME_FUTURE_PRIM_IS_UNARY_INLINED);
   scheme_add_global_constant("fsemaphore-try-wait?", p, newenv);  
 
   GLOBAL_PRIM_W_ARITY("would-be-future", would_be_future, 1, 1, newenv);
@@ -569,6 +560,8 @@ void scheme_init_futures(Scheme_Env *new
   scheme_protect_primitive_provide(newenv, NULL);
 }
 
+#ifdef MZ_USE_FUTURES
+
 void scheme_init_futures_once()
 {
   init_cpucount();
