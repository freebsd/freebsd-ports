--- calendar/libical/src/libical/icaltime.c.orig	Wed Aug 11 16:37:41 2004
+++ calendar/libical/src/libical/icaltime.c	Wed Aug 11 16:38:01 2004
@@ -334,7 +334,7 @@
     if(tzstr!=0){
 	putenv(tzstr);
     } else {
-	putenv("TZ"); /* Delete from environment */
+	unsetenv("TZ"); /* Delete from environment */
     } 
 
     /* Free any previous TZ environment string we have used. */
