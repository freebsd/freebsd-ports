--- src/bin/help.c.orig	2015-11-05 17:57:50 UTC
+++ src/bin/help.c
@@ -14,6 +14,7 @@ Authors: 1986 Wayne A. Christopher
 #include <pwd.h>
 #endif
 
+static char *hcopydev;
 #ifdef HAVE_X11
 
 #include <X11/Intrinsic.h>
@@ -22,7 +23,6 @@ Authors: 1986 Wayne A. Christopher
 Display *Xdisplay;
 static XtAppContext app_con;
 static Widget toplevel;
-static char *hcopydev;
 
 static String fallback_resources[] = {
     
@@ -188,7 +188,7 @@ int t;
 {
     if (!strcmp(n, kw_hcopydev)) {
         strcpy(r, hcopydev);
-        return (True);
+        return (1);
     }
     return (false);
 }
