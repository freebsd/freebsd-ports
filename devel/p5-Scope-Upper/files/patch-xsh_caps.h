--- xsh/caps.h.orig	2016-06-04 20:01:09 UTC
+++ xsh/caps.h
@@ -0,0 +1,47 @@
+#ifndef XSH_CAPS_H
+#define XSH_CAPS_H 1
+
+#define XSH_HAS_PERL(R, V, S) (PERL_REVISION > (R) || (PERL_REVISION == (R) && (PERL_VERSION > (V) || (PERL_VERSION == (V) && (PERL_SUBVERSION >= (S))))))
+
+#define XSH_HAS_PERL_BRANCH(R, V, S) (PERL_REVISION == (R) && PERL_VERSION == (V) && PERL_SUBVERSION >= (S))
+
+#define XSH_HAS_PERL_EXACT(R, V, S) ((PERL_REVISION == (R)) && (PERL_VERSION == (V)) && (PERL_SUBVERSION == (S)))
+
+#ifndef XSH_PERL_PATCHLEVEL
+# ifdef PERL_PATCHNUM
+#  define XSH_PERL_PATCHLEVEL PERL_PATCHNUM
+# else
+#  define XSH_PERL_PATCHLEVEL 0
+# endif
+#endif
+
+#define XSH_HAS_PERL_MAINT(R, V, S, P) (PERL_REVISION == (R) && PERL_VERSION == (V) && (XSH_PERL_PATCHLEVEL >= (P) || (!XSH_PERL_PATCHLEVEL && PERL_SUBVERSION >= (S))))
+
+#ifndef XSH_MULTIPLICITY
+# if defined(MULTIPLICITY)
+#  define XSH_MULTIPLICITY 1
+# else
+#  define XSH_MULTIPLICITY 0
+# endif
+#endif
+#if XSH_MULTIPLICITY
+# ifndef PERL_IMPLICIT_CONTEXT
+#  error MULTIPLICITY builds must set PERL_IMPLICIT_CONTEXT
+# endif
+# ifndef tTHX
+#  define tTHX PerlInterpreter*
+# endif
+#endif
+
+#if XSH_MULTIPLICITY && defined(USE_ITHREADS) && defined(dMY_CXT) && defined(MY_CXT) && defined(START_MY_CXT) && defined(MY_CXT_INIT) && (defined(MY_CXT_CLONE) || defined(dMY_CXT_SV))
+# define XSH_THREADSAFE 1
+#else
+# define XSH_THREADSAFE 0
+#endif
+
+/* Safe unless stated otherwise in Makefile.PL */
+#ifndef XSH_FORKSAFE
+# define XSH_FORKSAFE 1
+#endif
+
+#endif /* XSH_CAPS_H */
