
$FreeBSD$

--- src/misc.c	2002/06/01 21:08:46	1.1
+++ src/misc.c	2002/06/01 21:09:16
@@ -549,10 +549,8 @@
 chmod_error_details (char const *name, mode_t mode)
 {
   int e = errno;
-  char buf[10];
-  decode_mode (mode, buf);
-  ERROR ((0, e, _("%s: Cannot change mode to %s"),
-	  quotearg_colon (name), buf));
+  ERROR ((0, e, _("%s: Cannot change mode to 0%o"),
+	  quotearg_colon (name), mode));
 }
 
 void
