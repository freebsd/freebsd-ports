--- score.c.orig	1996-08-27 19:23:58 UTC
+++ score.c
@@ -797,7 +797,7 @@ static void CopyEntry(short i1, short i2
 }
 
 /* Extract one line from "text".  Return 0 if there is no line to extract. */
-char *getline(char *text, char *linebuf, int bufsiz)
+char *get_line(char *text, char *linebuf, int bufsiz)
 {
     if (*text == 0) {
 	*linebuf = 0;
@@ -938,7 +938,7 @@ char *skip_past_header(char *text)
 {
     char line[256];
     do {
-	text = getline(text, line, sizeof(line));
+	text = get_line(text, line, sizeof(line));
 	if (!text) return 0;
     } while (0 != strcmp(line, ""));
     return text;
@@ -982,7 +982,7 @@ static short ParseUserLevel(char *text, 
     char line[256];
     text = skip_past_header(text);
     if (!text) return E_READSCORE;
-    text = getline(text, line, sizeof(line));
+    text = get_line(text, line, sizeof(line));
     if (!text) return E_READSCORE;
     if (0 == strncmp(line, "Level: ", 7)) {
 	*lv = atoi(&line[7]);
@@ -999,7 +999,7 @@ static void DeleteAllEntries()
 }
 
 #define GRAB(tag, stmt) 					\
-    text = getline(text, line, sizeof(line)); 			\
+    text = get_line(text, line, sizeof(line)); 			\
     if (!text) return E_READSCORE; 		 		\
     if (0 == strncmp(line, tag, strlen(tag))) { stmt; } 	\
     else return E_READSCORE;
@@ -1070,7 +1070,7 @@ static short ParseScoreText(char *text, 
 {
     char line[256];
     do {
-	text = getline(text, line, sizeof(line));
+	text = get_line(text, line, sizeof(line));
 	if (!text) return E_READSCORE;
     } while (line[0] != '=');
     scoreentries = 0;
@@ -1091,7 +1091,7 @@ static short ParseScoreLine(int i, char 
     int rank;
     char rank_s[4];
     char line[256];
-    *text = getline(*text, line, sizeof(line));
+    *text = get_line(*text, line, sizeof(line));
     if (!*text) return 0;
     strncpy(rank_s, line, 4);
     rank = atoi(rank_s);
