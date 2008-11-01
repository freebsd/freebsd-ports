--- log.h	10 Jun 2008 01:00:34 -0000	1.23
+++ log.h	17 Oct 2008 08:51:46 -0000
@@ -47,6 +47,6 @@
 void	cvs_vlog(u_int, const char *, va_list);
 int	cvs_printf(const char *, ...) __attribute__((format(printf, 1, 2)));
 int	cvs_vprintf(const char *, va_list);
-void	fatal(const char *, ...) __dead __attribute__((format(printf, 1,2)));
+void	fatal(const char *, ...) __attribute__((format(printf, 1,2)));
 
 #endif	/* LOG_H */

