--- lib/regex.h.orig	Sun Jan 25 20:56:51 2004
+++ lib/regex.h	Sun Jan 25 20:59:22 2004
@@ -485,8 +485,8 @@
 #ifdef _REGEX_RE_COMP
 /* 4.2 bsd compatibility.  */
 /* CVS: don't use prototypes: they may conflict with system headers.  */
-extern char *re_comp _RE_ARGS (());
-extern int re_exec _RE_ARGS (());
+extern char *re_comp _RE_ARGS ((const char *));
+extern int re_exec _RE_ARGS ((const char *));
 #endif
 
 /* POSIX compatibility.  */
