--- src/getline.c.orig	Tue Mar 25 14:58:33 2003
+++ src/getline.c	Sun May 18 14:45:40 2003
@@ -1,5 +1,5 @@
 /*
- * getline.c Copyright (C) 2003 Michael Tindal
+ * getline.c Copyright (C) 2003 Alexander Nedotsukov
  *
  * This program is free software; you can redistribute it and/or modify it
  * under the terms of the GNU General Public License as published by the Free
@@ -20,35 +20,48 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
+#include <errno.h>
 
-int getline (char** line, int* size, int fd)
+/* GNU libc getline() compatibility */
+
+int
+getline(char** line, size_t* size, FILE* fp)
 {
-	int len, res;
-	short brk = 0;
-	char* buf = malloc(2096);
-	char buf2[1];
-	
-	strcpy (buf, "");
+	static const size_t line_grow_by = 80; /* in most texts line fits console */
+	int ch;
+	size_t i;
 
-	while (!brk)
-	{
-		if ((res = read(fd, buf2, 1)) < 0)
-			return -1;
-		if (res != 0) // check for end-of-line
-			strcat(buf, buf2);
-		if (buf2[0] == '\n' || res == 0)
-			brk = 1;
+	if (line == NULL || size == NULL || fp == NULL) { /* illegal call */
+		errno = EINVAL;
+		return -1;
 	}
-	
-	if (*line == NULL)	
-	{
-		*line = (char*)malloc(strlen(buf));
+	if (*line == NULL && *size) { /* logically incorrect */
+		errno = EINVAL;
+		return -1;
+	}
+
+	i = 0;
+	while (1) {
+		ch = fgetc(fp);
+		if (ch == EOF)
+			break;
+		/* ensure bufer still large enough for ch and trailing null */
+		if ((*size - i) <= 1) {
+			*line = (char*)realloc(*line, *size += line_grow_by);
+			if (*line == NULL) {
+				errno = ENOMEM;
+				return -1;
+			}
+		}
+		*(*line + i++) = (char)ch;
+		if (ch == '\n')
+			break;
 	}
 	
-	strcpy(*line, buf);
-	*size = strlen(*line);
+	*(*line + i) = 0;
 	
-	return *size;
+	return ferror(fp) ? -1 : i;
 }
 
 #endif
+
