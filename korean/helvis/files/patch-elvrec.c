--- elvrec.c.orig	Mon Mar 21 14:27:37 1994
+++ elvrec.c	Sun Jan 28 20:52:16 2001
@@ -10,6 +10,7 @@
  */
 
 
+#include <sys/param.h>
 #include <stdio.h>
 #include "config.h"
 #include "vi.h"
@@ -22,8 +23,8 @@
 	char	*basename;	/* the name of the file to recover */
 	char	*outname;	/* the name of the file to write to */
 {
-	char	pathname[500];	/* full pathname of the file to recover */
-	char	line[600];	/* a line from the /usr/preserve/Index file */
+	char	pathname[MAXPATHLEN]; /* full pathname of the file to recover */
+	char	line[MAXPATHLEN]; /* a line from the /usr/preserve/Index file */
 	int	ch;		/* a character from the text being recovered */
 	FILE	*from;		/* the /usr/preserve file, or /usr/preserve/Index */
 	FILE	*to;		/* the user's text file */
@@ -42,19 +43,15 @@
 		if (basename[0] != SLASH)
 # endif
 		{
-			ptr = getcwd(pathname, sizeof pathname);
-			if (ptr != pathname)
-			{
-				strcpy(pathname, ptr);
-			}
-			ptr = pathname + strlen(pathname);
-			*ptr++ = SLASH;
-			strcpy(ptr, basename);
+			if ((ptr = getcwd(pathname, sizeof pathname)) == NULL)
+				err(1, "getcwd() failed");
+			snprintf(pathname, sizeof(pathname), "%s/%s", ptr,
+			    basename);
 		}
 		else
 #endif
 		{
-			strcpy(pathname, basename);
+			strlcpy(pathname, basename, sizeof(pathname));
 		}
 	}
 
@@ -67,6 +64,8 @@
 	 * version of this file.
 	 */
 	from = fopen(PRSVINDEX, "r");
+	if (!from)
+		err(1, "fopen() %s failed", PRSVINDEX);
 	while (from && fgets(line, sizeof line, from))
 	{
 		/* strip off the newline from the end of the string */
