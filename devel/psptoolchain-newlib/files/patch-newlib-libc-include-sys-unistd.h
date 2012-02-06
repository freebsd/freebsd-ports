--- ./newlib/libc/include/sys/unistd.h.orig	2011-08-19 14:29:34.000000000 +0000
+++ ./newlib/libc/include/sys/unistd.h	2012-01-25 19:33:12.000000000 +0000
@@ -241,6 +241,7 @@
 void    _EXFUN(sync, (void));
 #endif
 
+#if !defined(__psp__)
 ssize_t _EXFUN(readlink, (const char *__path, char *__buf, size_t __buflen));
 #if defined(__CYGWIN__)
 ssize_t	_EXFUN(readlinkat, (int __dirfd1, const char *__path, char *__buf, size_t __buflen));
@@ -250,6 +251,7 @@
 int	_EXFUN(symlinkat, (const char *, int, const char *));
 int	_EXFUN(unlinkat, (int, const char *, int));
 #endif
+#endif
 
 #define	F_OK	0
 #define	R_OK	4
