--- src/arch/unix/x11/xaw/widgets/RegExp.h.orig	Sat Dec  4 19:31:32 1999
+++ src/arch/unix/x11/xaw/widgets/RegExp.h	Fri Sep 17 07:49:53 2004
@@ -34,6 +34,9 @@
 #if defined __FreeBSD__ || defined __NetBSD__
 #undef HAVE_REGEXP_H
 #endif
+#if defined __FreeBSD__
+#undef HAVE_REGEX_H
+#endif
 
 #if defined HAVE_REGEX_H      /* POSIX */
 
