--- gdkanji.c.orig	Fri Feb  2 05:23:56 2001
+++ gdkanji.c	Wed Feb  7 20:59:08 2001
@@ -103,14 +103,18 @@
 unsigned char *str;
 #endif
 {
-	static int whatcode;
+	static int whatcode = ASCII;
+	int oldcode = ASCII;
 	int c, i;
 	char *lang = NULL;
 
 	c = '\1';
 	i = 0;
 
-	if (whatcode == 0) whatcode = ASCII;
+	if (whatcode != EUCORSJIS && whatcode != ASCII) {
+		oldcode = whatcode;
+		whatcode = ASCII;
+	}
 	
 	while ((whatcode == EUCORSJIS || whatcode == ASCII) && c != '\0') {
 		if ((c = str[i++]) != '\0') {
@@ -167,7 +171,7 @@
 				if ((c >= 64 && c <= 126) || (c >= 128 && c <= 160))
 					whatcode = SJIS;
 				else
-				if (c >= 253 && c >= 254) whatcode = EUC;
+				if (c >= 253 && c <= 254) whatcode = EUC;
 				else
 				if (c >= 161 && c <= 252) whatcode = EUCORSJIS;
 			}
@@ -184,6 +188,8 @@
 		debug("Kanji code detected at %d byte.", i);
 #endif
 
+	if (whatcode == EUCORSJIS && oldcode != ASCII) whatcode = oldcode;
+
 	if (whatcode == EUCORSJIS) {
 		if (getenv ("LC_ALL")) lang = getenv ("LC_ALL");
 		else
@@ -310,7 +316,7 @@
 			error("invalid code specification: \"%s\" or \"%s\"",
 								EUCSTR, code);
 #endif
-		strcpy(to, from);
+		ustrcpy(to, from);
 		return;
 	}
 
@@ -328,7 +334,7 @@
 		else
 #endif
 			error("something happen");
-		strcpy(to, from);
+		ustrcpy(to, from);
 		return;
 	}
 
@@ -526,11 +532,10 @@
 
 	t = (unsigned char *)gdMalloc(BUFSIZ);
 	any2eucjp(t, s, BUFSIZ);
-	i = strlen(t);
+	i = strlen((const char *)t);
 	gdFree(t);
 	return i;
 }
-#endif
 
 #ifdef DEBUG
 int main()
@@ -543,7 +548,7 @@
 	while ( (c = fgetc(stdin)) != '\n' && i < BUFSIZ ) input[i++] = c;
 	input[i] = '\0';
 
-	printf("input : %d bytes\n", strlen(input));
+	printf("input : %d bytes\n", strlen((const char *)input));
 	printf("output: %d bytes\n", strwidth(input));
 
 	output = (unsigned char *)gdMalloc(BUFSIZ);
@@ -555,4 +560,5 @@
 
 	return 0;
 }
+#endif
 #endif
