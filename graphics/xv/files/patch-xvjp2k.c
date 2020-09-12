--- xvjp2k.c.orig	2007-05-14 01:04:37 UTC
+++ xvjp2k.c
@@ -76,7 +76,7 @@ static const char *fbasename,  /* File's base name, fo
 */
 int jas_getdbglevel(void) {return 0;}
 int jas_setdbglevel(int n) {return 0;}
-int jas_memdump(FILE *fp,void *data,size_t len) {return 0;}
+int jas_memdump(FILE *fp,const void *data,size_t len) {return 0;}
 
 int jas_eprintf(const char *fmt,...)         /* Handle JasPer Library message */
 {
