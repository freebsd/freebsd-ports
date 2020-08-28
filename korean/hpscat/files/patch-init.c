--- init.c.orig	1995-11-23 17:18:58.000000000 -0500
+++ init.c	2013-06-12 17:34:31.000000000 -0400
@@ -211,7 +211,7 @@
     Time = localtime(&T.tv_sec);
     sprintf(nalza, "%02d:%02d,    %d/%d/%d",
 	    Time->tm_hour,  Time->tm_min,
-            Time->tm_mon+1, Time->tm_mday, Time->tm_year );
+            Time->tm_mon+1, Time->tm_mday, Time->tm_year + 1900);
 }
 
 /***  EOF  ***/
