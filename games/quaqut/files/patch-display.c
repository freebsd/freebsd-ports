--- src/display.c.orig	Tue Sep 28 22:49:58 2004
+++ src/display.c	Thu Oct 19 17:50:41 2006
@@ -122,7 +122,9 @@
   
   if ( quaqut.options & QUAQUT_OPTION_LOGFILE )
     fclose(destination);
-  
+  else
+    fflush(stdout);
+    
   return 1;
 }
 
