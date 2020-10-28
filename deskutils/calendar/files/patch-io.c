--- io.c.orig	2020-10-28 20:58:10 UTC
+++ io.c
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
 
@@ -206,21 +254,6 @@ token(char *line, FILE *out, bool *skip)
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
@@ -248,7 +281,7 @@ cal_parse(FILE *in, FILE *out)
 	int month[MAXCOUNT];
 	int day[MAXCOUNT];
 	int year[MAXCOUNT];
-	bool skip = false;
+	int skip = 0;
 	char dbuf[80];
 	char *pp, p;
 	struct tm tm;
@@ -278,7 +311,7 @@ cal_parse(FILE *in, FILE *out)
 			}
 		}
 
-		if (skip)
+		if (skip != 0)
 			continue;
 
 		buf = line;
