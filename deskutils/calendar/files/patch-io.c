--- io.c.orig	2020-10-18 03:01:26 UTC
+++ io.c
@@ -71,7 +71,7 @@ enum {
 };
 
 const char *calendarFile = "calendar";	/* default calendar file */
-static const char *calendarHomes[] = {".calendar", _PATH_INCLUDE}; /* HOME */
+static const char *calendarHomes[] = {".calendar", _PATH_INCLUDE_LOCAL, _PATH_INCLUDE}; /* HOME */
 static const char *calendarNoMail = "nomail";/* don't sent mail if file exist */
 
 static char path[MAXPATHLEN];
@@ -134,18 +134,66 @@ cal_fopen(const char *file)
 }
 
 static int
-token(char *line, FILE *out, bool *skip)
+token(char *line, FILE *out, int *skip)
 {
 	char *walk, c, a;
 
 	if (strncmp(line, "endif", 5) == 0) {
-		*skip = false;
+		if (*skip > 0)
+			--*skip;
 		return (T_OK);
 	}
 
-	if (*skip)
+	if (strncmp(line, "ifdef", 5) == 0) {
+		walk = line + 5;
+		trimlr(&walk);
+
+		if (*walk == '\0') {
+			warnx("Expecting arguments after #ifdef");
+			return (T_ERR);
+		}
+
+		if (*skip != 0 || definitions == NULL || sl_find(definitions, walk) == NULL)
+			++*skip;
+
 		return (T_OK);
+	}
 
+	if (strncmp(line, "ifndef", 6) == 0) {
+		walk = line + 6;
+		trimlr(&walk);
+
+		if (*walk == '\0') {
+			warnx("Expecting arguments after #ifndef");
+			return (T_ERR);
+		}
+
+		if (*skip != 0 || (definitions != NULL && sl_find(definitions, walk) != NULL))
+			++*skip;
+
+		return (T_OK);
+	}
+
+	if (strncmp(line, "else", 4) == 0) {
+		walk = line + 4;
+		trimlr(&walk);
+
+		if (*walk != '\0') {
+			warnx("Expecting no arguments after #else");
+			return (T_ERR);
+		}
+
+		if (*skip == 0)
+			*skip = 1;
+		else if (*skip == 1)
+			*skip = 0;
+
+		return (T_OK);
+	}
+
+	if (*skip != 0)
+		return (T_OK);
+
 	if (strncmp(line, "include", 7) == 0) {
 		walk = line + 7;
 
@@ -161,26 +209,12 @@ token(char *line, FILE *out, bool *skip)
 			return (T_ERR);
 		}
 
-		a = *walk;
+		a = *walk == '<' ? '>' : '\"';
 		walk++;
 		c = walk[strlen(walk) - 1];
 
-		switch(c) {
-		case '>':
-			if (a != '<') {
-				warnx("Unterminated include expecting '\"'");
-				return (T_ERR);
-			}
-			break;
-		case '\"':
-			if (a != '\"') {
-				warnx("Unterminated include expecting '>'");
-				return (T_ERR);
-			}
-			break;
-		default:
-			warnx("Unterminated include expecting '%c'",
-			    a == '<' ? '>' : '\"' );
+		if (a != c) {
+			warnx("Unterminated include expecting '%c'", a);
 			return (T_ERR);
 		}
 		walk[strlen(walk) - 1] = '\0';
@@ -206,21 +240,6 @@ token(char *line, FILE *out, bool *skip)
 		return (T_OK);
 	}
 
-	if (strncmp(line, "ifndef", 6) == 0) {
-		walk = line + 6;
-		trimlr(&walk);
-
-		if (*walk == '\0') {
-			warnx("Expecting arguments after #ifndef");
-			return (T_ERR);
-		}
-
-		if (definitions != NULL && sl_find(definitions, walk) != NULL)
-			*skip = true;
-
-		return (T_OK);
-	}
-
 	return (T_PROCESS);
 
 }
@@ -248,11 +267,13 @@ cal_parse(FILE *in, FILE *out)
 	int month[MAXCOUNT];
 	int day[MAXCOUNT];
 	int year[MAXCOUNT];
-	bool skip = false;
+	int skip = 0;
 	char dbuf[80];
 	char *pp, p;
 	struct tm tm;
 	int flags;
+	char *c, *cc;
+	bool incomment = false;
 
 	/* Unused */
 	tm.tm_sec = 0;
@@ -264,8 +285,58 @@ cal_parse(FILE *in, FILE *out)
 		return (1);
 
 	while ((linelen = getline(&line, &linecap, in)) > 0) {
-		if (*line == '#') {
-			switch (token(line+1, out, &skip)) {
+		buf = line;
+		if (buf[linelen - 1] == '\n')
+			buf[--linelen] = '\0';
+
+		if (incomment) {
+			c = strstr(buf, "*/");
+			if (c) {
+				c += 2;
+				linelen -= c - buf;
+				buf = c;
+				incomment = false;
+			} else {
+				continue;
+			}
+		}
+		if (!incomment) {
+			do {
+				c = strstr(buf, "//");
+				cc = strstr(buf, "/*");
+				if (c != NULL && (cc == NULL || c - cc < 0)) {
+					/* single line comment */
+					*c = '\0';
+					linelen = c - buf;
+					break;
+				} else if (cc != NULL) {
+					c = strstr(cc + 2, "*/");
+					if (c != NULL) {
+						/* multi-line comment ending on same line */
+						c += 2;
+						memmove(cc, c, buf + linelen + 1 - c);
+						linelen -= c - cc;
+					} else {
+						/* multi-line comment */
+						*cc = '\0';
+						linelen = cc - buf;
+						incomment = true;
+						break;
+					}
+				}
+			} while (c != NULL || cc != NULL);
+		}
+
+		for (l = linelen;
+		     l > 0 && isspace((unsigned char)buf[l - 1]);
+		     l--)
+			;
+		buf[l] = '\0';
+		if (buf[0] == '\0')
+			continue;
+
+		if (buf == line && *buf == '#') {
+			switch (token(buf+1, out, &skip)) {
 			case T_ERR:
 				free(line);
 				return (1);
@@ -278,16 +349,7 @@ cal_parse(FILE *in, FILE *out)
 			}
 		}
 
-		if (skip)
-			continue;
-
-		buf = line;
-		for (l = linelen;
-		     l > 0 && isspace((unsigned char)buf[l - 1]);
-		     l--)
-			;
-		buf[l] = '\0';
-		if (buf[0] == '\0')
+		if (skip != 0)
 			continue;
 
 		/*
