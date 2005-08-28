--- src/getline.c.orig	Sun Aug 21 02:07:44 2005
+++ src/getline.c	Sun Aug 21 02:23:37 2005
@@ -1,70 +1,112 @@
-/*
- * getline.c Copyright (C) 2003 Alexander Nedotsukov
- *
- * This program is free software; you can redistribute it and/or modify it
- * under the terms of the GNU General Public License as published by the Free
- * Software Foundation; either version 2 of the License, or (at your option)
- * any later version.
- *
- * This program is distributed in the hope that it will be useful, but
- * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
- * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
- * for more details.
- * You should have received a copy of the GNU General Public License along
- * with this program; if not, write to the Free Software Foundation, Inc., 59
- * Temple Place, Suite 330, Boston, MA  02111-1307  USA
- */
+#include "config.h"
 
-#include <config.h>
-
-// #ifdef FREEBSD
 #ifndef HAVE_GETLINE
 
+#undef _GNU_SOURCE
+
+#include <sys/types.h>
 #include <stdio.h>
-#include <string.h>
-#include <stdlib.h>
-#include <errno.h>
 
-/* GNU libc getline() compatibility */
+#ifdef HAVE_STRINGS_H
+# include <strings.h>
+#else
+# include <string.h>
+#endif /* HAVE_STRINGS_H */
+
+#ifdef HAVE_STDLIB_H
+# include <stdlib.h>
+#endif /* HAVE_STDLIB_H */
+
+#ifdef HAVE_UNISTD_H
+# include <unistd.h>
+#endif /* HAVE_UNISTD_H */
+
+#include <limits.h>
+#include <errno.h>
 
-int
-getline(char** line, size_t* size, FILE* fp)
+/* Read up to (and including) a '\n' from STREAM into *LINEPTR
+   (and null-terminate it). *LINEPTR is a pointer returned from malloc (or
+   NULL), pointing to *N characters of space.  It is realloc'd as
+   necessary.  Returns the number of characters read (not including the
+   null terminator), or -1 on error or EOF.  */
+
+size_t
+getline (lineptr, n, stream)
+     char **lineptr;
+     size_t *n;
+     FILE *stream;
 {
-	static const size_t line_grow_by = 80; /* in most texts line fits console */
-	int ch;
-	size_t i;
-
-	if (line == NULL || size == NULL || fp == NULL) { /* illegal call */
-		errno = EINVAL;
-		return -1;
-	}
-	if (*line == NULL && *size) { /* logically incorrect */
-		errno = EINVAL;
-		return -1;
-	}
+  char *line, *p;
+  long size, copy;
 
-	i = 0;
-	while (1) {
-		ch = fgetc(fp);
-		if (ch == EOF)
-			break;
-		/* ensure bufer still large enough for ch and trailing null */
-		if ((*size - i) <= 1) {
-			*line = (char*)realloc(*line, *size += line_grow_by);
-			if (*line == NULL) {
-				errno = ENOMEM;
-				return -1;
-			}
-		}
-		*(*line + i++) = (char)ch;
-		if (ch == '\n')
-			break;
+  if (lineptr == NULL || n == NULL)
+    {
+      errno = EINVAL;
+      return (size_t) -1;
+    }
+
+  if (ferror (stream))
+    return (size_t) -1;
+
+  /* Make sure we have a line buffer to start with.  */
+  if (*lineptr == NULL || *n < 2) /* !seen and no buf yet need 2 chars.  */
+    {
+#ifndef	MAX_CANON
+#define	MAX_CANON	256
+#endif
+      if (!*lineptr)
+        line = (char *) malloc (MAX_CANON);
+      else
+        line = (char *) realloc (*lineptr, MAX_CANON);
+      if (line == NULL)
+	return (size_t) -1;
+      *lineptr = line;
+      *n = MAX_CANON;
+    }
+
+  line = *lineptr;
+  size = *n;
+
+  copy = size;
+  p = line;
+
+  while (1)
+    {
+      long len;
+      
+      while (--copy > 0)
+	{
+	  register int c = getc (stream);
+	  if (c == EOF)
+	    goto lose;
+	  else if ((*p++ = c) == '\n')
+	    goto win;
 	}
-	
-	*(*line + i) = 0;
-	
-	return ferror(fp) ? -1 : i;
+      
+      /* Need to enlarge the line buffer.  */
+      len = p - line;
+      size *= 2;
+      line = (char *) realloc (line, size);
+      if (line == NULL)
+	goto lose;
+      *lineptr = line;
+      *n = size;
+      p = line + len;
+      copy = size - len;
+    }
+
+ lose:
+  if (p == *lineptr)
+    return (size_t) -1;
+
+  /* Return a partial line since we got an error in the middle.  */
+ win:
+#if defined(WIN32) || defined(_WIN32) || defined(__CYGWIN__) || defined(MSDOS) || defined(__EMX__)
+  if (p - 2 >= *lineptr && p[-2] == '\r')
+    p[-2] = p[-1], --p;
+#endif
+  *p = '\0';
+  return p - *lineptr;
 }
 
 #endif
-
