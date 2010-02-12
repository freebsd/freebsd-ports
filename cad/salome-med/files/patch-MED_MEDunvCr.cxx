--- src/MEDWrapper/V2_1/Core/MEDunvCr.cxx.orig	2009-06-04 08:44:21.000000000 +0700
+++ src/MEDWrapper/V2_1/Core/MEDunvCr.cxx	2009-06-04 09:10:00.000000000 +0700
@@ -25,6 +25,10 @@
 #include <stdio.h>
 #include <time.h>
 
+#include <unistd.h>
+#include <sys/types.h>
+#include <pwd.h>
+
 //#ifdef PPRO_NT
 #ifdef WIN32
 // Windows Header Files:
@@ -51,6 +55,7 @@
   long   nSize   = UNLEN+1;
 #else
   struct timeval tp;
+  struct passwd *pwstr;
 #endif 
   med_err ret;
 
@@ -83,7 +88,9 @@
   nSize = (long)strlen(nomu)-1;
   if ( sprintf(&nomu[nSize]," %hu",tp.millitm) < 0 ) return -1;
 #else
-  if (cuserid(nomu) == (void*) NULL) return -1;
+//  if (cuserid(nomu) == (void*) NULL) return -1;
+  pwstr=getpwuid(getuid());
+  strncpy(nomu,pwstr->pw_name,MED_TAILLE_LNOM+1);
   strcat(nomu," ");
   temps=time(&temps);
   strcat(nomu,ctime(&temps));
