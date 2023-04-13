--- src/display.c.orig	2004-09-28 12:49:58 UTC
+++ src/display.c
@@ -122,7 +122,9 @@ int quaqut_display_process( int protocol , char comman
   
   if ( quaqut.options & QUAQUT_OPTION_LOGFILE )
     fclose(destination);
-  
+  else
+    fflush(stdout);
+    
   return 1;
 }
 
