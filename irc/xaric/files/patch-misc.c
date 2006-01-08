--- misc.c.orig	Wed Nov 30 11:06:26 2005
+++ misc.c	Sun Jan  8 21:45:27 2006
@@ -104,7 +104,7 @@
 
 char *convert_time(time_t ltime)
 {
-    time_t days = 0, hours = 0, minutes = 0, seconds = 0;
+    unsigned int days = 0, hours = 0, minutes = 0, seconds = 0;
     static char buffer[100];
 
     *buffer = '\0';
@@ -114,7 +114,7 @@
     ltime = (ltime - minutes) / 60;
     hours = ltime % 24;
     days = (ltime - hours) / 24;
-    sprintf(buffer, "%2ldd %2ldh %2ldm %2lds", days, hours, minutes, seconds);
+    sprintf(buffer, "%2ud %2uh %2um %2us", days, hours, minutes, seconds);
     return (*buffer ? buffer : empty_str);
 }
 
