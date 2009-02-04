--- gnokii/gnokii.c.orig	2009-02-03 23:23:35.000000000 +0100
+++ gnokii/gnokii.c	2009-02-03 23:24:01.000000000 +0100
@@ -1082,7 +1082,7 @@
 			else
 				len = strlen(input);
 			if (len > 0)
-				argv[argc++] = strndup(input, len);
+				argv[argc++] = strdup(input);
 			input = tmp;
 		} while (input);
 		argv[argc] = NULL;
