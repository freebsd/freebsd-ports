--- /usr/ports/audio/ascd/work/ascd-0.13.2/faktory.c	Mon Jul  5 20:52:38 1999
+++ faktory.c	Sat Sep  2 17:26:31 2000
@@ -58,9 +58,9 @@
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
