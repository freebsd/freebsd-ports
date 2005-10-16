--- src/presets.c.orig	Sat Nov  1 21:06:51 2003
+++ src/presets.c	Sat Oct 15 20:54:03 2005
@@ -20,6 +20,8 @@
 #include <config.h>
 #endif
 
+#include <sys/cdefs.h>
+#include <sys/syslimits.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -162,10 +164,10 @@
 	line = 1;
 
 	while (1) {
-		glr = getline(&linebuffer, &linebuffersize, f);
-
-		if (glr < 0)
+		if (fgets(linebuffer, linebuffersize, f) == NULL)
 			break;
+
+		glr = strlen(linebuffer);
 
 		line++;
 
