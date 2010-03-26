--- ./src/ci/MEDunvCr.c.orig	2009-07-06 17:49:32.000000000 +0200
+++ ./src/ci/MEDunvCr.c	2010-01-31 14:20:10.000000000 +0100
@@ -50,6 +50,12 @@
 
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
@@ -100,7 +106,11 @@
    goto ERROR;
   }
   strcat(nomu,mypasswd->pw_name);*/
+# ifdef __FreeBSD__
+  if ( !getpwuid(geteuid()) ) {
+# else
   if ( !cuserid(nomu) ) {
+# endif
    MESSAGE("Impossible d'obtenir le nom de l'utilisateur effectif");
    goto ERROR;
   }
