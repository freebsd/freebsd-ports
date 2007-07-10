--- eval.c.orig	Sun Mar 11 11:31:53 2007
+++ eval.c	Fri Jun  8 13:33:59 2007
@@ -1562,11 +1565,15 @@
     int ex;
 {
     int state;
-    volatile VALUE err = ruby_errinfo;
+    VALUE err;
+    volatile VALUE errs[2];
+    int nerr;
 
+    errs[0] = ruby_errinfo;
     ruby_safe_level = 0;
     Init_stack((void*)&state);
     ruby_finalize_0();
+    errs[1] = ruby_errinfo;
     PUSH_TAG(PROT_NONE);
     PUSH_ITER(ITER_NOT);
     if ((state = EXEC_TAG()) == 0) {
@@ -1577,15 +1584,15 @@
 	ex = state;
     }
     POP_ITER();
-    ruby_errinfo = err;
+    ruby_errinfo = errs[0];
     ex = error_handle(ex);
     ruby_finalize_1();
     POP_TAG();
 
-    if (err) {
+    for (nerr = sizeof(errs) / sizeof(errs[0]); nerr;) {
+	if (!(err = errs[--nerr])) continue;
 	if (rb_obj_is_kind_of(err, rb_eSystemExit)) {
-	    VALUE st = rb_iv_get(err, "status");
-	    return NUM2INT(st);
+	    return sysexit_status(err);
 	}
 	else if (rb_obj_is_kind_of(err, rb_eSignal)) {
 	    VALUE sig = rb_iv_get(err, "signo");
@@ -1855,7 +1862,7 @@
     POP_TAG();
     POP_FRAME();
 
-    jump_tag_but_local_jump(state, val);
+    if (state) jump_tag_but_local_jump(state, val);
     return val;
 }
 
@@ -3494,6 +3501,10 @@
 		    }
 		    argv = RARRAY(RBASIC(ruby_scope)->klass)->ptr;
 		}
+		else if (!ruby_scope->local_vars) {
+		    argc = 0;
+		    argv = 0;
+		}
 		else {
 		    argv = ruby_scope->local_vars + 2;
 		}
@@ -4998,8 +5009,10 @@
 	    CHECK_INTS;
 	    goto redo;
 	  case TAG_NEXT:
-	    state = 0;
-	    result = prot_tag->retval;
+	    if (!lambda) {
+		state = 0;
+		result = prot_tag->retval;
+	    }
 	    break;
 	  case TAG_BREAK:
 	    if (TAG_DST()) {
@@ -7017,7 +7030,8 @@
 	    return Qfalse;
 	}
 	else if (IS_SOEXT(ext) || IS_DLEXT(ext)) {
-	    return Qfalse;	/* may be overriden by .rb file */
+	    if (rb_feature_p(feature, ext, Qfalse)) return Qtrue;
+	    return Qfalse;
 	}
     }
     if (rb_feature_p(feature, feature + strlen(feature), Qtrue))
@@ -8597,6 +8611,7 @@
 	proc_jump_error(TAG_RETRY, Qnil); /* xxx */
 	JUMP_TAG(state);
 	break;
+      case TAG_NEXT:
       case TAG_BREAK:
 	if (!pcall && result != Qundef) {
 	    proc_jump_error(state, result);
@@ -8966,7 +8981,6 @@
 	   (FL_TEST(rklass, FL_SINGLETON) || TYPE(rklass) == T_ICLASS)) {
 	rklass = RCLASS(rklass)->super;
     }
-    if (TYPE(klass) == T_ICLASS) klass = RBASIC(klass)->klass;
     method = Data_Make_Struct(mklass, struct METHOD, bm_mark, free, data);
     data->klass = klass;
     data->recv = obj;
@@ -9441,8 +9455,12 @@
     else {
 	rb_str_buf_cat2(str, rb_class2name(data->rklass));
 	if (data->rklass != data->klass) {
+	    VALUE klass = data -> klass;
+	    if (TYPE(klass) == T_ICLASS) {
+		klass = RBASIC(klass)->klass;
+	    }
 	    rb_str_buf_cat2(str, "(");
-	    rb_str_buf_cat2(str, rb_class2name(data->klass));
+	    rb_str_buf_cat2(str, rb_class2name(klass));
 	    rb_str_buf_cat2(str, ")");
 	}
     }
@@ -11201,10 +11217,19 @@
 rb_thread_wakeup(thread)
     VALUE thread;
 {
+    if (!RTEST(rb_thread_wakeup_alive(thread)))
+	rb_raise(rb_eThreadError, "killed thread");
+    return thread;
+}
+
+VALUE
+rb_thread_wakeup_alive(thread)
+    VALUE thread;
+{
     rb_thread_t th = rb_thread_check(thread);
 
     if (th->status == THREAD_KILLED)
-	rb_raise(rb_eThreadError, "killed thread");
+	return Qnil;
     rb_thread_ready(th);
 
     return thread;
@@ -11630,6 +11657,15 @@
 }
 
 
+enum thread_status
+rb_thread_status(thread)
+    VALUE thread;
+{
+    rb_thread_t th = rb_thread_check(thread);
+    return th->status;
+}
+
+
 /*
  *  call-seq:
  *     thr.group   => thgrp or nil
@@ -11736,21 +11772,36 @@
     /* cause EINTR */
 }
 
+static int time_thread_alive_p = 0;
 static pthread_t time_thread;
 
 static void*
 thread_timer(dummy)
     void *dummy;
 {
+#ifdef _THREAD_SAFE
+#define test_cancel() pthread_testcancel()
+#else
+#define test_cancel() /* void */
+#endif
+
+    sigset_t all_signals;
+
+    sigfillset(&all_signals);
+    pthread_sigmask(SIG_BLOCK, &all_signals, 0);
+
     for (;;) {
 #ifdef HAVE_NANOSLEEP
 	struct timespec req, rem;
 
+	test_cancel();
 	req.tv_sec = 0;
 	req.tv_nsec = 10000000;
 	nanosleep(&req, &rem);
 #else
 	struct timeval tv;
+
+	test_cancel();
 	tv.tv_sec = 0;
 	tv.tv_usec = 10000;
 	select(0, NULL, NULL, NULL, &tv);
@@ -11762,6 +11813,7 @@
 	    }
 	}
     }
+#undef test_cancel
 }
 
 void
@@ -11773,6 +11825,20 @@
 rb_thread_stop_timer()
 {
 }
+
+void
+rb_thread_cancel_timer()
+{
+#ifdef _THREAD_SAFE
+    if( time_thread_alive_p )
+    {
+	pthread_cancel( time_thread );
+	pthread_join( time_thread, NULL );
+	time_thread_alive_p = 0;
+    }
+    thread_init = 0;
+#endif
+}
 #elif defined(HAVE_SETITIMER)
 static void
 catch_timer(sig)
@@ -11810,8 +11876,19 @@
     tval.it_value = tval.it_interval;
     setitimer(ITIMER_VIRTUAL, &tval, NULL);
 }
+
+void
+rb_thread_cancel_timer()
+{
+}
+
 #else  /* !(_THREAD_SAFE || HAVE_SETITIMER) */
 int rb_thread_tick = THREAD_TICK;
+
+void
+rb_thread_cancel_timer()
+{
+}
 #endif
 
 static VALUE
@@ -11842,6 +11919,7 @@
 
 #ifdef _THREAD_SAFE
 	pthread_create(&time_thread, 0, thread_timer, 0);
+        time_thread_alive_p = 1;
 #else
 	rb_thread_start_timer();
 #endif
@@ -12106,7 +12184,7 @@
  */
 
 static VALUE
-rb_thread_status(thread)
+rb_thread_status_name(thread)
     VALUE thread;
 {
     rb_thread_t th = rb_thread_check(thread);
@@ -12133,7 +12211,7 @@
  *     thr.alive?              #=> false
  */
 
-static VALUE
+VALUE
 rb_thread_alive_p(thread)
     VALUE thread;
 {
@@ -12967,7 +13045,7 @@
     rb_define_method(rb_cThread, "terminate!", rb_thread_kill_bang, 0);
     rb_define_method(rb_cThread, "exit!", rb_thread_kill_bang, 0);
     rb_define_method(rb_cThread, "value", rb_thread_value, 0);
-    rb_define_method(rb_cThread, "status", rb_thread_status, 0);
+    rb_define_method(rb_cThread, "status", rb_thread_status_name, 0);
     rb_define_method(rb_cThread, "join", rb_thread_join_m, -1);
     rb_define_method(rb_cThread, "alive?", rb_thread_alive_p, 0);
     rb_define_method(rb_cThread, "stop?", rb_thread_stop_p, 0);
