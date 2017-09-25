--- src/recompiler/dyngen-exec.h.orig	2017-09-13 09:34:47 UTC
+++ src/recompiler/dyngen-exec.h
@@ -75,10 +75,18 @@ typedef void * host_reg_t;
 # ifndef VBOX
 #define AREG0 "ebp"
 # else  /* VBOX - why are we different? frame-pointer optimizations on mac? */
+#  ifndef __clang__
 #  define AREG0 "esi"
+#  else  /* __clang __ */
+#   define AREG0 "ebp"
+#  endif /* __clang __ */
 # endif /* VBOX */
 #elif defined(__x86_64__)
+# ifndef __clang__
 #define AREG0 "r14"
+# else  /* __clang__ */
+#  define AREG0 "rbp"
+# endif /* __clang__ */
 #elif defined(_ARCH_PPC)
 #define AREG0 "r27"
 #elif defined(__arm__)
