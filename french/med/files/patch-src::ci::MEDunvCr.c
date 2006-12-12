--- ./src/ci/MEDunvCr.c.orig	Thu May 18 11:43:58 2006
+++ ./src/ci/MEDunvCr.c	Mon Dec 11 21:31:06 2006
@@ -43,6 +43,12 @@
 
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
@@ -87,7 +93,11 @@
   nSize = strlen(nomu)-1;
   if ( sprintf(&nomu[nSize]," %hu",tp.millitm) < 0 ) return -1;
 #else
+# ifdef __FreeBSD__
+  if ( !getpwuid(geteuid()) ) return -1;
+# else
   if ( !cuserid(nomu) ) return -1;
+# endif
   strcat(nomu," ");
   temps=time(&temps);
   strcat(nomu,ctime(&temps));
