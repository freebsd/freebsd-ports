--- subs.c.orig	2005-01-24 06:16:01 UTC
+++ subs.c
@@ -74,7 +74,7 @@ int ask_spell_subs(char **replace, int *
 	subtask= 1;
 	sprintf(st,"Replacement for \"%.*s\" (? for help): ",
 		strlen(match+1)-1, match+1);
-	if (getline(*replace= bf,NULL,wcol,st))
+	if (get_line(*replace= bf,NULL,wcol,st))
 	{
 	    printf("\nSpell Check Interupted.\n");
 	    do_subs= 'q';
@@ -429,7 +429,7 @@ int cliplast(char *lastbuf, int bufsize)
 #endif
 
     /* Make a copy of the file */
-    if ((cfp= make_copy()) == NULL) return;
+    if ((cfp= make_copy()) == NULL) return 0;
     fflush(cfp);
     fseek(cfp,0L,0);
 
