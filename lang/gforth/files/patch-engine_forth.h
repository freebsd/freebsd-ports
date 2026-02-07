--- engine/forth.h.orig	2013-10-11 21:31:28 UTC
+++ engine/forth.h
@@ -490,7 +490,7 @@ extern double asinh(double r1);
 extern double acosh(double r1);
 #endif
 #ifndef HAVE_ECVT
-/* extern char* ecvt(double x, int len, int* exp, int* sign);*/
+extern char* ecvt(double x, int len, int* exp, int* sign);
 #endif
 #ifndef HAVE_MEMMOVE
 /* extern char *memmove(char *dest, const char *src, long n); */
