--- xsh/util.h.orig	2016-06-04 20:01:09 UTC
+++ xsh/util.h
@@ -0,0 +1,97 @@
+#ifndef XSH_UTIL_H
+#define XSH_UTIL_H 1
+
+#include "caps.h" /* XSH_HAS_PERL() */
+
+#ifndef XSH_PACKAGE
+# error XSH_PACKAGE must be defined
+#endif
+
+#define XSH_PACKAGE_LEN (sizeof(XSH_PACKAGE)-1)
+
+#ifdef DEBUGGING
+# if XSH_HAS_PERL(5, 8, 9) || XSH_HAS_PERL(5, 9, 3)
+#  define XSH_ASSERT(C) assert(C)
+# else
+#  define XSH_ASSERT(C) PERL_DEB( \
+   ((C) ? ((void) 0)           \
+        : (Perl_croak_nocontext("Assertion %s failed: file \"" __FILE__  \
+                                 "\", line %d", STRINGIFY(C), __LINE__), \
+           (void) 0)))
+# endif
+#else
+# define XSH_ASSERT(C)
+#endif
+
+#undef VOID2
+#ifdef __cplusplus
+# define VOID2(T, P) static_cast<T>(P)
+#else
+# define VOID2(T, P) (P)
+#endif
+
+#ifndef STMT_START
+# define STMT_START do
+#endif
+
+#ifndef STMT_END
+# define STMT_END while (0)
+#endif
+
+#ifndef dNOOP
+# define dNOOP
+#endif
+
+#ifndef NOOP
+# define NOOP
+#endif
+
+#if XSH_HAS_PERL(5, 13, 2)
+# define XSH_DUP_PARAMS_TYPE       CLONE_PARAMS *
+# define xsh_dup_params_init(P, O) ((P) = Perl_clone_params_new((O), aTHX))
+# define xsh_dup_params_deinit(P)  Perl_clone_params_del(P)
+# define xsh_dup_params_ptr(P)     (P)
+#else
+# define XSH_DUP_PARAMS_TYPE       CLONE_PARAMS
+# define xsh_dup_params_init(P, O) \
+      ((P).stashes = newAV()); (P).flags = 0; ((P).proto_perl = (O))
+# define xsh_dup_params_deinit(P)  SvREFCNT_dec((P).stashes)
+# define xsh_dup_params_ptr(P)     &(P)
+#endif
+#define xsh_dup(S, P)     sv_dup((S), (P))
+#define xsh_dup_inc(S, P) SvREFCNT_inc(xsh_dup((S), (P)))
+
+/* Context for PerlMemShared_*() functions */
+#ifdef PERL_IMPLICIT_SYS
+# define pPMS  pTHX
+# define pPMS_ pTHX_
+# define aPMS  aTHX
+# define aPMS_ aTHX_
+#else
+# define pPMS  void
+# define pPMS_
+# define aPMS
+# define aPMS_
+#endif
+
+#ifdef USE_ITHREADS
+# define XSH_LOCK(M)   MUTEX_LOCK(M)
+# define XSH_UNLOCK(M) MUTEX_UNLOCK(M)
+#else
+# define XSH_LOCK(M)   NOOP
+# define XSH_UNLOCK(M) NOOP
+#endif
+
+#ifndef PTR2nat
+# define PTR2nat(p) (PTRV)(p)
+#endif
+
+#ifndef DPTR2FPTR
+# define DPTR2FPTR(t,p) ((t)PTR2nat(p))
+#endif
+
+#ifndef FPTR2DPTR
+# define FPTR2DPTR(t,p) ((t)PTR2nat(p))
+#endif
+
+#endif /* XSH_UTIL_H */
