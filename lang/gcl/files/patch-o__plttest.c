--- o/plttest.c.orig
+++ o/plttest.c
@@ -11,11 +11,13 @@
 #define DARWIN
 #endif
 
+#ifndef __FreeBSD__
 #ifndef DARWIN
 extern int _mcount();
 #define mmcount _mcount
 extern void sincos(double,double *,double *);
 #endif
+#endif
 
 int
 main(int argc,char * argv[],char *envp[]) {
