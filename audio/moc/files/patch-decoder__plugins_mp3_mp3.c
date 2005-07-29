--- decoder_plugins/mp3/mp3.c.orig	Wed Jun 15 18:56:45 2005
+++ decoder_plugins/mp3/mp3.c	Fri Jul 29 14:28:05 2005
@@ -353,10 +353,13 @@
 	
 	debug ("Processing file %s", file);
 
-	if (!(data = mp3_open_internal(file, 0)))
-		time = -1;
-	else
+	data = mp3_open_internal (file, 0);
+	
+	if (data->ok)
 		time = data->duration;
+	else
+		time = -1;
+	
 	mp3_close (data);
 
 	return time;
