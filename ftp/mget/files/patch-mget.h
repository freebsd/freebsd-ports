--- mget.h.orig	Sat Sep 22 00:34:48 2001
+++ mget.h	Sat Sep 22 00:35:03 2001
@@ -60,9 +60,11 @@
 #define herror(A) printf("%s\n",A)
 #endif
 
+/*
 #if !defined(__linux__) || !defined(HAVE_IPV6)
 char *inet_ntop(int , INADDR *, char *, size_t );
 #endif
+*/
 
 #ifndef NULL 
 #define NULL 0 //some compilers complained
