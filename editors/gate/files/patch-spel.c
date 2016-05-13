--- spel.c.orig	2003-06-19 16:55:51 UTC
+++ spel.c
@@ -683,7 +683,7 @@ int fix_word(char *line, int offset, int
     for(;;)
     {
 	subtask= 1;
-	if (getline(bf,NULL,&wcol,st))
+	if (get_line(bf,NULL,&wcol,st))
 	{
 	    printf("\nSpell Check Interupted.\n");
 	    return 1;
