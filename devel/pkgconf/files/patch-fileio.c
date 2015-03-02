diff --git fileio.c fileio.c
index fed3da9..2e15833 100644
--- fileio.c
+++ fileio.c
@@ -37,13 +37,22 @@ pkg_fgetline(char *line, size_t size, FILE *stream)
 
 		else if (c == '\n')
 		{
-			*s++ = c;
-
 			if (quoted)
 			{
+				/* Trim spaces */
+				do {
+					c2 = getc(stream);
+				} while (c2 == '\t' || c2 == ' ');
+
+				ungetc(c2, stream);
+
 				quoted = false;
 				continue;
 			}
+			else
+			{
+				*s++ = c;
+			}
 
 			break;
 		}
