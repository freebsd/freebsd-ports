--- scmfig.h
+++ scmfig.h
@@ -256,11 +256,7 @@
 #ifdef __alpha
 # define SHORT_INT
 #endif
-#ifdef __ia64__
-# define SHORT_INT
-# define CDR_DOUBLES
-#endif
-#ifdef __x86_64
+#if defined(__amd64__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__) || defined(__sparc64__)
 # define SHORT_INT
 # define CDR_DOUBLES
 #endif
@@ -393,14 +389,6 @@
 # define WHITE_SPACES  ' ':case '\t':case '\r':case '\f'
 #endif
 
-#ifdef __ia64__
-# define PTR2INT(x) ((long)(x))
+#define PTR2INT(x) ((intptr_t)(x))
-#else
-# ifdef __x86_64
-#  define PTR2INT(x) ((long)(x))
-# else
-#  define PTR2INT(x) ((int)(x))
-# endif
-#endif
 
 #ifndef __builtin_expect
@@ -824,5 +816,5 @@
 # ifdef ARM_ULIB
     extern volatile int errno;
-# else
+# elif defined(PLAN9)
     extern int errno;
 # endif
