--- src/calc.c.orig	Tue Jun  3 01:11:20 2003
+++ src/calc.c	Wed Jun  4 13:38:50 2003
@@ -30,6 +30,8 @@
 #include <signal.h>
 #ifdef HAVE_WORDEXP
 #include <wordexp.h>
+#else
+#include <glob.h>
 #endif
 #include <stdio.h>
 #include <string.h>
@@ -2402,7 +2404,7 @@
 		return NULL;
 	}
 	for (i = 0; i < gl.gl_pathc; i++) {
-		list = g_slist_prepend (list, g_strdup (gl.gl_pathc[i]));
+		list = g_slist_prepend (list, g_strdup (gl.gl_pathv[i]));
 	}
 	globfree (&gl);
 #endif
