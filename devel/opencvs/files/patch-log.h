--- log.h.orig	2008-06-10 03:00:34.000000000 +0200
+++ log.h	2010-06-08 20:18:08.000000000 +0200
@@ -47,6 +47,6 @@
 void	cvs_vlog(u_int, const char *, va_list);
 int	cvs_printf(const char *, ...) __attribute__((format(printf, 1, 2)));
 int	cvs_vprintf(const char *, va_list);
-void	fatal(const char *, ...) __dead __attribute__((format(printf, 1,2)));
+void	fatal(const char *, ...) __attribute__((format(printf, 1,2)));
 
 #endif	/* LOG_H */
