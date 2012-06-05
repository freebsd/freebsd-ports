--- nec2c.h.orig	2012-06-05 13:34:14.000000000 -0500
+++ nec2c.h	2012-06-05 13:34:45.000000000 -0500
@@ -201,8 +201,8 @@
 void 	secnds(double *x);
 int 	stop(int flag);
 int 	load_line(char *buff, FILE *pfile);
-void	mem_alloc( void **ptr, int req );
-void	mem_realloc( void **ptr, int req );
+void	mem_alloc( void **ptr, size_t req );
+void	mem_realloc( void **ptr, size_t req );
 void	free_ptr( void **ptr );
 /* somnec.c */
 void 	somnec(double epr, double sig, double fmhz);
