--- Src/dd_pinit.c.orig	Fri Apr  7 21:12:59 2006
+++ Src/dd_pinit.c	Thu Sep  7 19:16:32 2006
@@ -230,7 +230,7 @@
     FH_Clear();
     ArgShutdown();
     Z_Shutdown();
-    DD_ShutdownDGL();
+    //DD_ShutdownDGL();
 
     // Close the message output file.
     fclose(outFile);
