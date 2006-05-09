--- Src/dd_pinit.c.orig
+++ Src/dd_pinit.c
@@ -226,7 +226,7 @@
 	FH_Clear();
 	ArgShutdown();
     Z_Shutdown();
-	DD_ShutdownDGL();
+	//DD_ShutdownDGL();
 
 	// Close the message output file.
 	fclose(outFile);
