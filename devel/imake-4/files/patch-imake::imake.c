
$FreeBSD$

--- imake/imake.c	2002/05/10 23:41:31	1.1
+++ imake/imake.c	2002/05/10 23:42:02
@@ -1161,7 +1161,7 @@
 get_gcc_incdir(FILE *inFile)
 {
   static char* gcc_path[] = {
-#if defined(linux) || defined(__OpenBSD__) || defined (__GNU__)
+#if defined(linux) || defined(__OpenBSD__) || defined (__GNU__) || defined(__FreeBSD__)
     "/usr/bin/cc",	/* for Linux PostIncDir */
 #endif
     "/usr/local/bin/gcc",
