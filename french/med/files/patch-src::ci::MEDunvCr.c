--- ./src/ci/MEDunvCr.c.orig	Tue Dec 10 16:48:14 2002
+++ ./src/ci/MEDunvCr.c	Fri Jun 27 16:10:48 2003
@@ -34,6 +34,12 @@
 #include <sys/time.h>
 #endif
 
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <unistd.h>
+#include <pwd.h>
+#endif
+
 med_err 
 MEDunvCr(med_idt fid, char *maa)
 {
@@ -78,7 +84,11 @@
   nSize = strlen(nomu)-1;
   if ( sprintf(&nomu[nSize]," %hu",tp.millitm) < 0 ) return -1;
 #else
+# ifdef __FreeBSD__
+  if (getpwuid(geteuid()) == NULL) return -1;
+# else
   if (cuserid(nomu) == (void*) NULL) return -1;
+# endif
   strcat(nomu," ");
   temps=time(&temps);
   strcat(nomu,ctime(&temps));
