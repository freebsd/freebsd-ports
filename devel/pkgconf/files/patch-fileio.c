--- ./fileio.c.orig	2014-06-07 22:32:08.000000000 +0200
+++ ./fileio.c	2014-08-04 11:24:32.522803742 +0200
@@ -83,10 +83,18 @@
 
 	}
 
-	*s = '\0';
-
 	if (c == EOF && (s == line || ferror(stream)))
 		return NULL;
 
+	*s = '\0';
+
+	/* Remove newline character. */
+	if (s > line && *(--s) == '\n') {
+		*s = '\0';
+
+		if (s > line && *(--s) == '\r')
+			*s = '\0';
+	}
+
 	return line;
 }
