--- io.c.orig	2020-10-29 11:04:06 UTC
+++ io.c
@@ -209,26 +209,12 @@ token(char *line, FILE *out, int *skip)
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
