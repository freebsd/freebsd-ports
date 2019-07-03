It's not really NORETURN, since it jumps around (via longjmp())
back to the main loop, but at that point we've pretty much reached
UB anyway.

--- ddd/exit.C.orig	2019-07-03 20:06:15 UTC
+++ ddd/exit.C
@@ -769,7 +769,7 @@ static void PostXtErrorCB(XtPointer client_data, XtInt
 
 static XtAppContext xt_error_app_context = 0;
 
-static void ddd_xt_error(String message = 0)
+static _X_NORETURN void ddd_xt_error(String message = 0)
 {
     ddd_has_crashed = true;
 
