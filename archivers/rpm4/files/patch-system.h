--- system.h.orig	2017-02-16 09:40:09 UTC
+++ system.h
@@ -41,6 +41,13 @@ char * stpncpy(char * dest, const char *
 #define	getenv(_s)	__secure_getenv(_s)
 #endif
 
+/* Add includes for missing libc prototypes */
+#include <ctype.h>
+#include <string.h>
+#include <libgen.h>
+#include <sys/wait.h>
+#include <netinet/in.h>
+
 #ifdef HAVE_FCNTL_H
 #include <fcntl.h>
 #else
@@ -87,7 +94,7 @@ char * stpncpy(char * dest, const char *
 #define _free(_ptr) rfree((_ptr))
 
 /* Retrofit glibc __progname */
-#if defined __GLIBC__ && __GLIBC__ >= 2
+#if defined __GLIBC__ && __GLIBC__ >= 2 || defined(__FreeBSD__)
 #if __GLIBC_MINOR__ >= 1
 #define	__progname	__assert_program_name
 #endif
