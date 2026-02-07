--- src/validate.cpp.orig	2003-03-31 04:49:41 UTC
+++ src/validate.cpp
@@ -34,6 +34,10 @@
 #include <iostream>
 #include <strstream>
 #include <iomanip>
+#include <netdb.h>
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
 
 using namespace std;
 
@@ -47,11 +51,17 @@ struct user_info {
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
 
@@ -140,12 +150,21 @@ int  checkSystemPass(const string szUser, const string
     pam_end(pamh, PAM_SUCCESS);
     return 0;
 #else
+#ifdef BSD
     passwd *ppw = NULL;
+    struct group *pgrp = NULL;
+    struct spwd *pspwd = NULL;
+    char *member = NULL;
+    struct group grp;
+    struct passwd pwd;
+#else
+    passwd *ppw = NULL;
     group *pgrp = NULL;
     spwd *pspwd = NULL;
     char *member = NULL;
     struct group grp;
     struct passwd pwd;
+#endif
     int i;
     char salt[16];
     int usrfound = 0 ;
@@ -158,7 +177,11 @@ int  checkSystemPass(const string szUser, const string
 #endif
 
   
+#ifdef BSD
+    size_t bufsize=MAXGROUPSIZE;
+#else
     size_t bufsize = sysconf(_SC_GETGR_R_SIZE_MAX);
+#endif
     char *buffer1 = new char[bufsize];
     //Thread-Safe getgrnam()
     getgrnam_r(szGroup.c_str(),         /* Does group name szGroup exist? */
@@ -168,12 +191,14 @@ int  checkSystemPass(const string szUser, const string
                 &pgrp);
 
     if (pgrp == NULL) {
-        delete buffer1;
+        delete[] buffer1;
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
@@ -183,8 +208,8 @@ int  checkSystemPass(const string szUser, const string
                 &ppw);
 
     if (ppw == NULL){ 
-        delete buffer2;
-        delete buffer1;
+        delete[] buffer2;
+        delete[] buffer1;
         return BADUSER ; /* return BADUSER if no such user */
     }
    
@@ -200,8 +225,8 @@ int  checkSystemPass(const string szUser, const string
     }
 
     if (usrfound == 0) { 
-        delete buffer1;
-        delete buffer2;
+        delete[] buffer1;
+        delete[] buffer2;
         return BADGROUP;	 /* return BADGROUP if user not in group */
     }
 
@@ -214,6 +239,7 @@ int  checkSystemPass(const string szUser, const string
 
     pwLength = strlen(ppw->pw_passwd);
 
+#if 0
     if (ppw->pw_passwd[0] != '$') {
         /* DES salt */
         strncpy(salt,ppw->pw_passwd,2);
@@ -230,15 +256,18 @@ int  checkSystemPass(const string szUser, const string
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
@@ -246,8 +275,8 @@ int  checkSystemPass(const string szUser, const string
         pspwd = getspnam(szUser.c_str());  //Get shadow password file data for user
         if (pspwd == NULL) {
             cout << "validate: Can't read shadowed password file.  This program must run as root\n";
-            delete buffer1;
-            delete buffer2;
+            delete[] buffer1;
+            delete[] buffer2;
             return MUSTRUNROOT;
         }
         pwLength = strlen(pspwd->sp_pwdp);
@@ -288,8 +317,9 @@ int  checkSystemPass(const string szUser, const string
             << endl;
 #endif
     }
-    delete buffer1;
-    delete buffer2;
+#endif
+    delete[] buffer1;
+    delete[] buffer2;
     return rc;
 #endif
 }
