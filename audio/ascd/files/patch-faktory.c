--- faktory.c.orig	1999-07-05 16:52:38 UTC
+++ faktory.c
@@ -58,9 +58,9 @@ int fak_parse_line(char *ligne, char *ke
     unsigned int pos = 0;
 
     if ((strlen(ligne) > 0) && (ligne[0] != '#')) {
-	while ((ligne[pos] != ' ') && (ligne[pos] != 9)) pos++;
+	while (ligne[pos] && (ligne[pos] != ' ') && (ligne[pos] != 9)) pos++;
 	tes_sncpy(key, ligne, pos);
-	while (((ligne[pos] == ' ') || (ligne[pos] == 9)) && (pos < strlen(ligne))) pos++;
+	while (ligne[pos] && ((ligne[pos] == ' ') || (ligne[pos] == 9))) pos++;
 	if (pos < strlen(ligne)) strcpy(arguments, ligne + pos);
 	else strcpy(arguments, "");
 	if (debug > 2) fprintf(stderr,"++ input: [%s]\n   key:   [%s]\n   args:  [%s]\n", ligne, key, arguments);
