--- src/audioscrobbler.c.orig	Fri Jun 22 02:50:36 2007
+++ src/audioscrobbler.c	Fri Jun 22 02:50:52 2007
@@ -743,6 +743,8 @@ static void queue_load(void)
 	}
 	
 	while (getline(&line, &buffer_size, cache_file) != -1) {
+		if (line == NULL)
+			break;
 		char *p = strchr(line, '\n');
 		if (p != NULL)
 			*p = '\0';
