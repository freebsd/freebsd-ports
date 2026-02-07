--- tetrinet.c.orig	2003-10-05 18:39:24 UTC
+++ tetrinet.c
@@ -83,7 +83,7 @@ void parse(char *buf)
 		winlist[i].team = 0;
 	    s++;
 	    strncpy(winlist[i].name, s, sizeof(winlist[i].name)-1);
-	    winlist[i].name[sizeof(winlist[i].name)] = 0;
+	    winlist[i].name[sizeof(winlist[i].name)-1] = 0;
 	    winlist[i].points = atoi(t);
 	    if ((t = strchr(t, ';')) != NULL)
 		winlist[i].games = atoi(t+1);
