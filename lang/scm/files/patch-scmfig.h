--- scmfig.h.orig
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
+#if defined(__amd64__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__)
 # define SHORT_INT
 # define CDR_DOUBLES
 #endif
@@ -393,14 +389,10 @@
 # define WHITE_SPACES  ' ':case '\t':case '\r':case '\f'
 #endif
 
-#ifdef __ia64__
+# if defined(__amd64__) || defined(__ia64__) || defined(__powerpc64__) || defined(__x86_64__)
 # define PTR2INT(x) ((long)(x))
 #else
-# ifdef __x86_64
-#  define PTR2INT(x) ((long)(x))
-# else
-#  define PTR2INT(x) ((int)(x))
-# endif
+# define PTR2INT(x) ((int)(x))
 #endif
 
 #ifndef __builtin_expect
