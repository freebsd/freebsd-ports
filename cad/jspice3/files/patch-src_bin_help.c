--- src/bin/help.c.intermediate	2014-08-18 06:30:22.000000000 +0000
+++ src/bin/help.c
@@ -53,7 +53,7 @@ XErrorEvent *errorev;
 
     XGetErrorText(display, errorev->error_code, ErrorMessage, 1024);
     printf(ErrorMessage);
-    return;
+    return (NULL);
 }   
 
 
