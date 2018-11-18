--- scmfig.h	2013-04-06 22:23:52.000000000 -0400
+++ scmfig.h	2018-11-18 13:05:53.787326000 -0500
@@ -257,9 +257,5 @@
 # define SHORT_INT
 #endif
-#ifdef __ia64__
-# define SHORT_INT
-# define CDR_DOUBLES
-#endif
-#ifdef __x86_64
+#if defined(__amd64__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__sparc64__) || defined(__arch64__)
 # define SHORT_INT
 # define CDR_DOUBLES
@@ -394,13 +390,5 @@
 #endif
 
-#ifdef __ia64__
-# define PTR2INT(x) ((long)(x))
-#else
-# ifdef __x86_64
-#  define PTR2INT(x) ((long)(x))
-# else
-#  define PTR2INT(x) ((int)(x))
-# endif
-#endif
+#define PTR2INT(x) ((intptr_t)(x))
 
 #ifndef __builtin_expect
@@ -538,5 +526,5 @@
 # define MAKINUM(x) ((((x)<<1)<<1)+2L)
 #else
-# define MAKINUM(x) (((x)<<2)+2L)
+# define MAKINUM(x) ((((unsigned long)(x))<<2)+2L)
 #endif
 
@@ -824,5 +812,5 @@
 # ifdef ARM_ULIB
     extern volatile int errno;
-# else
+# elif defined(PLAN9)
     extern int errno;
 # endif
