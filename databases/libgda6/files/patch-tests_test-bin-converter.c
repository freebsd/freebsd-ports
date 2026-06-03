--- tests/test-bin-converter.c.orig	2025-03-02 15:03:58 UTC
+++ tests/test-bin-converter.c
@@ -67,6 +67,6 @@ main (G_GNUC_UNUSED int argc, G_GNUC_UNUSED char** arg
 	gda_binary_free (bin);
 	gda_binary_free (bin2);
 
-	g_print ("Ok (file size: %ld)\n", bin_length);
+	g_print ("Ok (file size: %ld)\n", (long)bin_length);
 	return EXIT_SUCCESS;
 }
