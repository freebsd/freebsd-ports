--- cvswrap.c.orig	2009-02-24 15:40:55.000000000 +0100
+++ cvswrap.c	2009-02-24 15:38:24.000000000 +0100
@@ -94,7 +94,9 @@
     char **cvsrootp);
 static void	slashfix(char *);
 static int	strings_have_line(char * const *strings, const char *line);
+#if !defined(__FreeBSD__)
 static char *	strndup(const char *str, size_t len);
+#endif
 static int	timeval_diff(const struct timeval *tv1,
     const struct timeval *tv2);
 static int	writebuf(int fd, const char *buf, size_t len);
@@ -324,6 +329,7 @@
 	return (0);
 }
 
+#if !defined(__FreeBSD__)
 /*
  * return: a copy of "len" bytes from byte string "str" and NULL terminate.
  */
@@ -340,6 +348,7 @@
 		*(ret + len) = '\0';
 	return (ret);
 }
+#endif
 
 /*
  * Wait for child cvs process to exit.
