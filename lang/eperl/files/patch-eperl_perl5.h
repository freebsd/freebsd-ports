--- ./eperl_perl5.h.orig	1998-07-10 03:52:13.000000000 -0400
+++ ./eperl_perl5.h	2009-01-29 13:27:30.000000000 -0500
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
