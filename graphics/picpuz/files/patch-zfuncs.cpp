--- zfuncs.cpp.orig	2009-10-02 03:20:15.000000000 +0700
+++ zfuncs.cpp	2009-10-07 12:35:45.000000000 +0700
@@ -23,6 +23,11 @@
 //     zfuncs version  v.2.25
 
 #include "zfuncs.h"
+#ifdef __FreeBSD__
+#include <sys/wait.h>
+#include <sys/types.h>
+#include <pwd.h>
+#endif
 
 /**************************************************************************
    system-level utility functions
@@ -2875,7 +2880,7 @@
    strcpy(zicondir,zdatadir);
    strcat(zicondir,"/icons");
 
-   pp = cuserid(0);
+   pp = getpwuid(geteuid())->pw_name;
    if (strEqu(pp,"root")) snprintf(zuserdir,199,"/root/.%s",zappname);     //  get /root/.appname
    else snprintf(zuserdir,199,"%s/.%s",getenv("HOME"),zappname);           //  or /home/user/.appname
 
