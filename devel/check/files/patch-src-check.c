Revert:		https://github.com/libcheck/check/commit/7ac1fcbcefe8813e2a75388ec61e20a184ddc8c8

--- src/check.c.orig	2020-07-22 14:19:48 UTC
+++ src/check.c
@@ -362,24 +362,25 @@ void _mark_point(const char *file, int line)
     send_loc_info(file, line);
 }
 
-void _ck_assert_failed(const char *file, int line, const char *expr,
-                       const char *msg, ...)
+void _ck_assert_failed(const char *file, int line, const char *expr, ...)
 {
+    const char *msg;
+    va_list ap;
     char buf[BUFSIZ];
     const char *to_send;
 
     send_loc_info(file, line);
 
+    va_start(ap, expr);
+    msg = (const char *)va_arg(ap, char *);
+
     /*
      * If a message was passed, format it with vsnprintf.
      * Otherwise, print the expression as is.
      */
     if(msg != NULL)
     {
-        va_list ap;
-        va_start(ap, msg);
         vsnprintf(buf, BUFSIZ, msg, ap);
-        va_end(ap);
         to_send = buf;
     }
     else
@@ -387,6 +388,7 @@ void _ck_assert_failed(const char *file, int line, con
         to_send = expr;
     }
 
+    va_end(ap);
     send_failure_info(to_send);
     if(cur_fork_status() == CK_FORK)
     {
