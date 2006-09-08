--- config.m4.orig	Fri Sep  8 07:42:50 2006
+++ config.m4	Fri Sep  8 07:43:00 2006
@@ -66,7 +66,6 @@
 int foo(int x, ...) {
 	va_list va;
 	va_start(va, x);
-	va_arg(va, int);
 	va_arg(va, char *);
 	va_arg(va, double);
 	return 0;
