--- ext/impl/posix_serialport.c.orig	2009-07-30 11:59:13.000000000 +0400
+++ ext/impl/posix_serialport.c	2009-07-30 12:07:49.000000000 +0400
@@ -568,7 +568,7 @@
    return Qnil;
 }
 
-static void get_line_signals_helper_impl(obj, ls)
+static void get_line_signals_helper(obj, ls)
    VALUE obj;
    struct line_signals *ls;
 {
@@ -589,7 +589,7 @@
    ls->ri  = (status & TIOCM_RI ? 1 : 0);
 }
 
-static VALUE set_signal_impl(obj, val, sig)
+static VALUE set_signal(obj, val, sig)
    VALUE obj,val;
    int sig;
 {
