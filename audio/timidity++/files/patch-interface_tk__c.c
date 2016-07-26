--- interface/tk_c.c.orig	2011-12-03 15:49:19 UTC
+++ interface/tk_c.c
@@ -913,7 +913,7 @@ static char *v_eval(char *fmt, ...)
 	vsnprintf(buf, sizeof(buf), fmt, ap);
 	Tcl_Eval(my_interp, buf);
 	va_end(ap);
-	return my_interp->result;
+	return Tcl_GetStringResult(my_interp);
 }
 
 static const char *v_get2(const char *v1, const char *v2)
