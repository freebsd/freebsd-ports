--- src/readword.c~	Sun Nov 21 20:55:42 2004
+++ src/readword.c	Sun Nov 21 20:58:22 2004
@@ -26,13 +26,14 @@
 
 	gboolean return_val = 0;
 	
-	int n,i;
+	int n=0,i;
 	
 
 	if(have_data_file && word && g_ascii_isalpha(word[0]))
 	{
-		n=strlen(word);
 		gchar *lowerword = (gchar *)g_malloc(n+1);
+		gchar *filename;
+		n=strlen(word);
 		
 		for (i=0;i < n;i++)
 		{
@@ -40,7 +41,7 @@
 		}
 			lowerword[n] = '\0';
 		
-		gchar *filename = g_strdup_printf(
+		filename = g_strdup_printf(
 				RP_TTS_DIR"%c/%s.wav", 
 				lowerword[0],lowerword);		
 		
@@ -61,9 +62,11 @@
 	int n,i;
 	if (word && g_ascii_isalpha(word[0])) 
 	{
-		n=strlen(word);
 		
 		gchar *lowerword = (gchar *)g_malloc(n+1);
+		gchar *filename;
+		int fd;
+		n=strlen(word);
 		
 		for (i=0;i < n;i++)
 		{
@@ -72,15 +75,12 @@
 		
 		lowerword[n] = '\0';
 		
-		
-		gchar *filename;
-		
 		filename = g_strdup_printf(
 				RP_TTS_DIR"%c/%s.wav", 
 				lowerword[0],lowerword);		
 
 		//gnome_sound_play(filename);
-		int fd = esd_open_sound(NULL);
+		fd = esd_open_sound(NULL);
 		if (fd >= 0)
 		{
 			esd_play_file(NULL,filename, 0);
