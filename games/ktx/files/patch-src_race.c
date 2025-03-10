--- src/race.c.orig	2025-02-16 18:01:44 UTC
+++ src/race.c
@@ -3541,10 +3541,9 @@ char* race_fgets(char *buf, int limit)
 		return NULL;
 	}
 
-	string = buf;
-	while (--limit > 0 && ((c = race_fgetc()) != -1))
+	for (string = buf; --limit > 0 && (c = race_fgetc()) != -1; string++)
 	{
-		if ((*string++ = c) == '\n')
+		if ((*string = c) == '\n')
 		{
 			break;
 		}
