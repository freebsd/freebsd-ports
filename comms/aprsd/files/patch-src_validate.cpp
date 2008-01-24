--- src/validate.cpp.orig	2008-01-13 20:00:27.000000000 -0500
+++ src/validate.cpp	2008-01-13 20:45:17.000000000 -0500
@@ -34,6 +34,10 @@
 #include <iostream>
 #include <strstream>
 #include <iomanip>
+#include <netdb.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
 
 using namespace std;
 
@@ -47,11 +51,17 @@
    const string group;
 };
 #else
+#ifdef BSD
+#include <pwd.h>
+#include <grp.h>
+#define MAXGROUPSIZE 1024
+#else
 #include <crypt.h>
 #include <grp.h>
 #include <pwd.h>
 #include <shadow.h>
 #endif
+#endif
 
 #include "validate.h"
 
@@ -140,12 +150,21 @@
     pam_end(pamh, PAM_SUCCESS);
     return 0;
 #else
+#ifdef BSD
+    passwd *ppw = NULL;
+    struct group *pgrp = NULL;
+    struct spwd *pspwd = NULL;
+    char *member = NULL;
+    struct group grp;
+    struct passwd pwd;
+#else
     passwd *ppw = NULL;
     group *pgrp = NULL;
     spwd *pspwd = NULL;
     char *member = NULL;
     struct group grp;
     struct passwd pwd;
+#endif
     int i;
     char salt[16];
     int usrfound = 0 ;
@@ -158,7 +177,11 @@
 #endif
 
   
+#ifdef BSD
+    size_t bufsize=MAXGROUPSIZE;
+#else
     size_t bufsize = sysconf(_SC_GETGR_R_SIZE_MAX);
+#endif
     char *buffer1 = new char[bufsize];
     //Thread-Safe getgrnam()
     getgrnam_r(szGroup.c_str(),         /* Does group name szGroup exist? */
@@ -171,9 +194,11 @@
         delete buffer1;
         return rc;	  /* return BADGROUP if not */
     }
-
+#ifdef BSD
+    bufsize = MAXGROUPSIZE;
+#else
     bufsize = sysconf(_SC_GETPW_R_SIZE_MAX);
-   
+#endif   
     char *buffer2 = new char[bufsize];
     //Thread-Safe getpwnam()
     getpwnam_r(szUser.c_str(),
@@ -214,6 +239,7 @@
 
     pwLength = strlen(ppw->pw_passwd);
 
+#if 0
     if (ppw->pw_passwd[0] != '$') {
         /* DES salt */
         strncpy(salt,ppw->pw_passwd,2);
@@ -230,15 +256,18 @@
         salt[i++] = '$';
         salt[i] = '\0';
     }
+#endif
+
 #ifdef DEBUG
     cout << "salt=" << salt << endl;
 #endif
 
-    if (strcmp(crypt(szPass.c_str(), salt), ppw->pw_passwd) == 0 ) 
+    if (strcmp(crypt(szPass.c_str(), ppw->pw_passwd), ppw->pw_passwd) == 0 ) 
         rc = 0; 
     else 
         rc = BADPASSWD;
 
+#ifndef BSD	/* BSD passwords are always shadowed */
     if ((rc == BADPASSWD) && (strcmp("x",ppw->pw_passwd) == 0)) {
 #ifdef DEBUG
         cout << "Shadow passwords enabled\n";
@@ -288,6 +317,7 @@
             << endl;
 #endif
     }
+#endif
     delete buffer1;
     delete buffer2;
     return rc;
