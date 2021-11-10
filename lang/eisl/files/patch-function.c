--- function.c.orig	2021-11-10 01:54:06 UTC
+++ function.c
@@ -2127,7 +2127,7 @@ f_read(int arglist)
                     save,
                     n,
                     res;
-#if __linux || __APPLE__ || defined(__OpenBSD__)
+#if __linux || __APPLE__ || defined(__OpenBSD__) || defined(__FreeBSD__)
     int             save1;
 #endif
 
@@ -2139,7 +2139,7 @@ f_read(int arglist)
     if (n > 0 && !input_stream_p(arg1))
 	error(NOT_IN_STREAM, "read", arg1);
 
-#if __linux || __APPLE__ || defined(__OpenBSD__)
+#if __linux || __APPLE__ || defined(__OpenBSD__) || defined(__FreeBSD__)
     save1 = repl_flag;
     repl_flag = 0;
 #endif
@@ -2151,7 +2151,7 @@ f_read(int arglist)
 	res = sread();
 	input_stream = save;
 	if (res == FEND) {
-#if __linux || __APPLE__ || defined(__OpenBSD__)
+#if __linux || __APPLE__ || defined(__OpenBSD__) || defined(__FreeBSD__)
 	    repl_flag = save1;
 #endif
 	    error(END_STREAM, "read", NIL);
@@ -2163,7 +2163,7 @@ f_read(int arglist)
 	res = sread();
 	input_stream = save;
 	if (res == FEND) {
-#if __linux || __APPLE__ || defined(__OpenBSD__)
+#if __linux || __APPLE__ || defined(__OpenBSD__) || defined(__FreeBSD__)
 	    repl_flag = save1;
 #endif
 	    if (nullp(arg2) && n == 2)
@@ -2174,7 +2174,7 @@ f_read(int arglist)
 		error(END_STREAM, "read", NIL);
 	}
     }
-#if __linux || __APPLE__ || defined(__OpenBSD__)
+#if __linux || __APPLE__ || defined(__OpenBSD__) || defined(__FreeBSD__)
     repl_flag = save1;
 #endif
     return (res);
@@ -2374,7 +2374,7 @@ f_read_line(int arglist)
                     res,
                     c;
     char            rl_buf[LINE_MAX];
-#if __linux || __APPLE__ || defined(__OpenBSD__)
+#if __linux || __APPLE__ || defined(__OpenBSD__) || defined(__FreeBSD__)
     int             save1;
 #endif
 
