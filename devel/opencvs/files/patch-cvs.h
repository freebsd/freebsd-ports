--- cvs.h	27 Jun 2008 21:14:15 -0000	1.172
+++ cvs.h	17 Oct 2008 08:51:45 -0000
@@ -433,5 +433,6 @@
 int	cvs_watch(int, char **);
 int	cvs_watchers(int, char **);
 
+#define SIZE_MAX ULONG_MAX
 
 #endif

