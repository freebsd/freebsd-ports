--- src/sentencewin.c~	Sun Nov 21 20:55:21 2004
+++ src/sentencewin.c	Sun Nov 21 20:55:28 2004
@@ -114,8 +114,8 @@
 //sentence read aloudly
 static void sentence_read()
 {
-	g_print("sentence read!!\n");
 	gchar word[256];
+	g_print("sentence read!!\n");
 	
 	strcpy(word,gtk_entry_get_text(GTK_ENTRY(input_entry)));
 
