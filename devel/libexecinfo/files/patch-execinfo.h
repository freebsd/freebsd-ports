
$FreeBSD$

--- execinfo.h	2003/08/10 05:43:54	1.1
+++ execinfo.h	2003/08/10 05:44:11
@@ -29,8 +29,16 @@
 #ifndef _EXECINFO_H_
 #define _EXECINFO_H_
 
+#ifdef __cplusplus
+extern "C" {
+#endif
+
 int     backtrace(void **, int);
 char ** backtrace_symbols(void *const *, int);
 void    backtrace_symbols_fd(void *const *, int, int);
+
+#ifdef __cplusplus
+}
+#endif
 
 #endif /* _EXECINFO_H_ */
