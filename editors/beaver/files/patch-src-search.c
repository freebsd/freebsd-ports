--- src/search.c.orig	Tue Jun 17 16:18:40 2003
+++ src/search.c	Tue Jun 17 16:25:24 2003
@@ -31,7 +31,7 @@
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>
-#include <wordexp.h>
+#include <glob.h>
 #include "tools.h"
 #include "editor.h"
 #include "struct.h"
@@ -375,7 +375,7 @@
 static gchar **get_files_for_search (const gchar *directory, const gchar *regexp, gint pre)
 {
 	gchar **answer;
-	wordexp_t word;
+	glob_t word;
 	
 	START_FCN
 	
@@ -387,8 +387,8 @@
 	*/
 	chdir (directory);
 	
-	word.we_offs = pre;
-	if (wordexp (regexp, &word, WRDE_DOOFFS))
+	word.gl_offs = pre;
+	if (glob (regexp, GLOB_DOOFFS, NULL, &word))
 	{
 		gint i;
 		
@@ -408,15 +408,15 @@
 		
 		/* fill out our array with results */
 		answer = g_malloc (sizeof (gchar *) * 
-			(word.we_wordc + word.we_offs + 1));
-		for (i = word.we_offs; i < word.we_offs + word.we_wordc; i++)
+			(word.gl_pathc + word.gl_offs + 1));
+		for (i = word.gl_offs; i < word.gl_offs + word.gl_pathc; i++)
 		{
-			answer[i] = g_strdup (word.we_wordv[i]);
+			answer[i] = g_strdup (word.gl_pathv[i]);
 		}
 		answer[i] = NULL;
 	}
 	
-	wordfree (&word);
+	globfree (&word);
 	
 	END_FCN
 	return answer;
