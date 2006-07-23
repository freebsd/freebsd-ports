--- src/bin/help.c.orig	Fri Jul 21 06:16:08 2006
+++ src/bin/help.c	Fri Jul 21 06:18:15 2006
@@ -14,6 +14,7 @@
 #include <pwd.h>
 #endif
 
+static char *hcopydev;
 #ifdef HAVE_X11
 
 #include <X11/Intrinsic.h>
@@ -22,7 +23,6 @@
 Display *Xdisplay;
 static XtAppContext app_con;
 static Widget toplevel;
-static char *hcopydev;
 
 static String fallback_resources[] = {
     
@@ -188,7 +188,7 @@
 {
     if (!strcmp(n, kw_hcopydev)) {
         strcpy(r, hcopydev);
-        return (True);
+        return (1);
     }
     return (false);
 }
