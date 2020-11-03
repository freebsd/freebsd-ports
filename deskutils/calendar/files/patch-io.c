--- io.c.orig	2020-10-18 03:01:26 UTC
+++ io.c
@@ -71,10 +71,14 @@ enum {
 };
 
 const char *calendarFile = "calendar";	/* default calendar file */
-static const char *calendarHomes[] = {".calendar", _PATH_INCLUDE}; /* HOME */
+static const char *calendarHomes[] = {".calendar", _PATH_INCLUDE_LOCAL, _PATH_INCLUDE}; /* HOME */
 static const char *calendarNoMail = "nomail";/* don't sent mail if file exist */
 
 static char path[MAXPATHLEN];
+static const char *cal_home;
+static const char *cal_dir;
+static const char *cal_file;
+static int cal_line;
 
 struct fixs neaster, npaskha, ncny, nfullmoon, nnewmoon;
 struct fixs nmarequinox, nsepequinox, njunsolstice, ndecsolstice;
@@ -85,22 +89,29 @@ static StringList *definitions = NULL;
 static struct event *events[MAXCOUNT];
 static char *extradata[MAXCOUNT];
 
-static void
+static char *
 trimlr(char **buf)
 {
 	char *walk = *buf;
+	char *sep;
 	char *last;
 
 	while (isspace(*walk))
 		walk++;
-	if (*walk != '\0') {
-		last = walk + strlen(walk) - 1;
+	*buf = walk;
+
+	sep = walk;
+	while (*sep != '\0' && !isspace(*sep))
+		sep++;
+
+	if (*sep != '\0') {
+		last = sep + strlen(sep) - 1;
 		while (last > walk && isspace(*last))
 			last--;
 		*(last+1) = 0;
 	}
 
-	*buf = walk;
+	return (sep);
 }
 
 static FILE *
@@ -116,7 +127,7 @@ cal_fopen(const char *file)
 	}
 
 	if (chdir(home) != 0) {
-		warnx("Cannot enter home directory");
+		warnx("Cannot enter home directory \"%s\"", home);
 		return (NULL);
 	}
 
@@ -124,8 +135,12 @@ cal_fopen(const char *file)
 		if (chdir(calendarHomes[i]) != 0)
 			continue;
 
-		if ((fp = fopen(file, "r")) != NULL)
+		if ((fp = fopen(file, "r")) != NULL) {
+			cal_home = home;
+			cal_dir = calendarHomes[i];
+			cal_file = file;
 			return (fp);
+		}
 	}
 
 	warnx("can't open calendar file \"%s\"", file);
@@ -133,60 +148,154 @@ cal_fopen(const char *file)
 	return (NULL);
 }
 
+static char*
+cal_path(void)
+{
+	static char buffer[MAXPATHLEN + 10];
+
+	if (cal_dir[0] == '/')
+		snprintf(buffer, sizeof(buffer), "%s/%s", cal_dir, cal_file);
+	else
+		snprintf(buffer, sizeof(buffer), "%s/%s/%s", cal_home, cal_dir, cal_file);
+	return (buffer);
+}
+
+#define	WARN0(format)		   \
+	warnx(format " in %s line %d", cal_path(), cal_line)
+#define	WARN1(format, arg1)		   \
+	warnx(format " in %s line %d", arg1, cal_path(), cal_line)
+
 static int
-token(char *line, FILE *out, bool *skip)
+token(char *line, FILE *out, int *skip, int *unskip)
 {
-	char *walk, c, a;
+	char *walk, *sep, a, c;
+	const char *this_cal_home;
+	const char *this_cal_dir;
+	const char *this_cal_file;
+	int this_cal_line;
 
 	if (strncmp(line, "endif", 5) == 0) {
-		*skip = false;
+		if (*skip > 0)
+			--*skip;
+		else if (*unskip > 0)
+			--*unskip;
+		else {
+			WARN0("#endif without prior #ifdef or #ifndef");
+			return (T_ERR);
+		}
+
 		return (T_OK);
 	}
 
-	if (*skip)
+	if (strncmp(line, "ifdef", 5) == 0) {
+		walk = line + 5;
+		sep = trimlr(&walk);
+
+		if (*walk == '\0') {
+			WARN0("Expecting arguments after #ifdef");
+			return (T_ERR);
+		}
+		if (*sep != '\0') {
+			WARN1("Expecting a single word after #ifdef "
+			    "but got \"%s\"", walk);
+			return (T_ERR);
+		}
+
+		if (*skip != 0 ||
+		    definitions == NULL || sl_find(definitions, walk) == NULL)
+			++*skip;
+		else
+			++*unskip;
+		
 		return (T_OK);
+	}
 
+	if (strncmp(line, "ifndef", 6) == 0) {
+		walk = line + 6;
+		sep = trimlr(&walk);
+
+		if (*walk == '\0') {
+			WARN0("Expecting arguments after #ifndef");
+			return (T_ERR);
+		}
+		if (*sep != '\0') {
+			WARN1("Expecting a single word after #ifndef "
+			    "but got \"%s\"", walk);
+			return (T_ERR);
+		}
+
+		if (*skip != 0 ||
+		    (definitions != NULL && sl_find(definitions, walk) != NULL))
+			++*skip;
+		else
+			++*unskip;
+
+		return (T_OK);
+	}
+
+	if (strncmp(line, "else", 4) == 0) {
+		walk = line + 4;
+		(void)trimlr(&walk);
+
+		if (*walk != '\0') {
+			WARN0("Expecting no arguments after #else");
+			return (T_ERR);
+		}
+
+		if (*unskip == 0) {
+			if (*skip == 0) {
+				WARN0("#else without prior #ifdef or #ifndef");
+				return (T_ERR);
+			} else if (*skip == 1) {
+				*skip = 0;
+				*unskip = 1;
+			}
+		} else if (*unskip == 1) {
+			*skip = 1;
+			*unskip = 0;
+		}
+
+		return (T_OK);
+	}
+
+	if (*skip != 0)
+		return (T_OK);
+
 	if (strncmp(line, "include", 7) == 0) {
 		walk = line + 7;
 
-		trimlr(&walk);
+		(void)trimlr(&walk);
 
 		if (*walk == '\0') {
-			warnx("Expecting arguments after #include");
+			WARN0("Expecting arguments after #include");
 			return (T_ERR);
 		}
 
 		if (*walk != '<' && *walk != '\"') {
-			warnx("Excecting '<' or '\"' after #include");
+			WARN0("Excecting '<' or '\"' after #include");
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
+			WARN1("Unterminated include expecting '%c'", a);
 			return (T_ERR);
 		}
 		walk[strlen(walk) - 1] = '\0';
 
+		this_cal_home = cal_home;
+		this_cal_dir = cal_dir;
+		this_cal_file = cal_file;
+		this_cal_line = cal_line;
 		if (cal_parse(cal_fopen(walk), out))
 			return (T_ERR);
+		cal_home = this_cal_home;
+		cal_dir = this_cal_dir;
+		cal_file = this_cal_file;
+		cal_line = this_cal_line;
 
 		return (T_OK);
 	}
@@ -195,29 +304,38 @@ token(char *line, FILE *out, bool *skip)
 		if (definitions == NULL)
 			definitions = sl_init();
 		walk = line + 6;
-		trimlr(&walk);
+		sep = trimlr(&walk);
+		*sep = '\0';
 
 		if (*walk == '\0') {
-			warnx("Expecting arguments after #define");
+			WARN0("Expecting arguments after #define");
 			return (T_ERR);
 		}
 
-		sl_add(definitions, strdup(walk));
+		if (sl_find(definitions, walk) == NULL)
+			sl_add(definitions, strdup(walk));
 		return (T_OK);
 	}
 
-	if (strncmp(line, "ifndef", 6) == 0) {
-		walk = line + 6;
-		trimlr(&walk);
+	if (strncmp(line, "undef", 5) == 0) {
+		if (definitions != NULL) {
+			walk = line + 5;
+			sep = trimlr(&walk);
 
-		if (*walk == '\0') {
-			warnx("Expecting arguments after #ifndef");
-			return (T_ERR);
-		}
+			if (*walk == '\0') {
+				WARN0("Expecting arguments after #undef");
+				return (T_ERR);
+			}
+			if (*sep != '\0') {
+				WARN1("Expecting a single word after #undef "
+				    "but got \"%s\"", walk);
+				return (T_ERR);
+			}
 
-		if (definitions != NULL && sl_find(definitions, walk) != NULL)
-			*skip = true;
-
+			walk = sl_find(definitions, walk);
+			if (walk != NULL)
+				walk[0] = '\0';
+		}
 		return (T_OK);
 	}
 
@@ -248,11 +366,14 @@ cal_parse(FILE *in, FILE *out)
 	int month[MAXCOUNT];
 	int day[MAXCOUNT];
 	int year[MAXCOUNT];
-	bool skip = false;
+	int skip = 0;
+	int unskip = 0;
 	char dbuf[80];
 	char *pp, p;
 	struct tm tm;
 	int flags;
+	char *c, *cc;
+	bool incomment = false;
 
 	/* Unused */
 	tm.tm_sec = 0;
@@ -263,9 +384,61 @@ cal_parse(FILE *in, FILE *out)
 	if (in == NULL)
 		return (1);
 
+	cal_line = 0;
 	while ((linelen = getline(&line, &linecap, in)) > 0) {
-		if (*line == '#') {
-			switch (token(line+1, out, &skip)) {
+		cal_line++;
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
+			switch (token(buf+1, out, &skip, &unskip)) {
 			case T_ERR:
 				free(line);
 				return (1);
@@ -278,18 +451,9 @@ cal_parse(FILE *in, FILE *out)
 			}
 		}
 
-		if (skip)
+		if (skip != 0)
 			continue;
 
-		buf = line;
-		for (l = linelen;
-		     l > 0 && isspace((unsigned char)buf[l - 1]);
-		     l--)
-			;
-		buf[l] = '\0';
-		if (buf[0] == '\0')
-			continue;
-
 		/*
 		 * Setting LANG in user's calendar was an old workaround
 		 * for 'calendar -a' being run with C locale to properly
@@ -298,8 +462,7 @@ cal_parse(FILE *in, FILE *out)
 		 * and does not run iconv(), this variable has little use.
 		 */
 		if (strncmp(buf, "LANG=", 5) == 0) {
-			(void)setlocale(LC_ALL, buf + 5);
-			d_first = (*nl_langinfo(D_MD_ORDER) == 'd');
+			(void)setlocale(LC_CTYPE, buf + 5);
 #ifdef WITH_ICONV
 			if (!doall)
 				set_new_encoding();
@@ -353,7 +516,7 @@ cal_parse(FILE *in, FILE *out)
 		if (count < 0) {
 			/* Show error status based on return value */
 			if (debug)
-				fprintf(stderr, "Ignored: %s\n", buf);
+				WARN1("Ignored: \"%s\"", buf);
 			if (count == -1)
 				continue;
 			count = -count + 1;
@@ -373,11 +536,15 @@ cal_parse(FILE *in, FILE *out)
 			(void)strftime(dbuf, sizeof(dbuf),
 			    d_first ? "%e %b" : "%b %e", &tm);
 			if (debug)
-				fprintf(stderr, "got %s\n", pp);
+				WARN1("got \"%s\"", pp);
 			events[i] = event_add(year[i], month[i], day[i], dbuf,
 			    ((flags &= F_VARIABLE) != 0) ? 1 : 0, pp,
 			    extradata[i]);
 		}
+	}
+	while (skip-- > 0 || unskip-- > 0) {
+		cal_line++;
+		WARN0("Missing #endif assumed");
 	}
 
 	free(line);
