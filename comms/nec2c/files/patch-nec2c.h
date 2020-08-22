--- nec2c.h.orig	2004-01-24 13:48:26 UTC
+++ nec2c.h
@@ -201,8 +201,8 @@ complex double cmplx(double a, double j);
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
