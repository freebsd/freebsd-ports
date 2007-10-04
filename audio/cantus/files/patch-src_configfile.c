--- src/configfile.c.orig	2003-05-17 04:46:45.000000000 -0800
+++ src/configfile.c	2007-10-03 14:15:05.000000000 -0800
@@ -269,7 +269,7 @@
 			&& strcmp(option, option_src) == 0 )
 		{
 			free(data);
-			(gchar *)fileitem->data = malloc(2048);
+			fileitem->data = malloc(2048);
 			data = (gchar *)fileitem->data;
 			snprintf(data, 2047, "%s = \"%s\"", option, value);
 			success = TRUE;
