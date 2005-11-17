--- Src/dd_pinit.c.orig
+++ Src/dd_pinit.c
@@ -227,7 +227,7 @@
 	FH_Clear();
 	ArgShutdown();
 	free(mainzone);
-	DD_ShutdownDGL();
+//	DD_ShutdownDGL();
 
 	// Close the message output file.
 	fclose(outFile);
