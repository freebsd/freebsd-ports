--- source/help.c.orig	2019-05-29 09:55:50 UTC
+++ source/help.c
@@ -311,7 +311,7 @@ help_topic(u_char *path, u_char *name)
 #ifdef ZCAT
 		if (my_strcmp(name + (my_strlen(name) - my_strlen(ZSUFFIX)), ZSUFFIX))
 		{
-			malloc_snprintf(&filename, "%s/%s%s", path, ZSUFFIX);
+			malloc_snprintf(&filename, "%s/%s%s", path, name, ZSUFFIX);
 			if (stat(CP(filename), &sb) == -1)
 			{
 				new_free(&filename);
