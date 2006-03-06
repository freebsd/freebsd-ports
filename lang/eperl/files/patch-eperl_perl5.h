$FreeBSD$

--- eperl_perl5.h.orig  Fri Jul 10 07:52:13 1998
+++ eperl_perl5.h       Wed Mar  1 12:12:32 2006
@@ -43,10 +43,10 @@


 /*  try to adjust for PerlIO handling  */
-#ifdef USE_PERLIO
-#undef  fwrite
-#define fwrite(buf,size,count,f) PerlIO_write(f,buf,size*count)
-#endif
+/* #ifdef USE_PERLIO */
+/* #undef  fwrite */
+/* #define fwrite(buf,size,count,f) PerlIO_write(f,buf,size*count) */
+/* #endif */


 /*  define the I/O type string for verbosity */
