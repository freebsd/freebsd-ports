--- breakpoints.c.orig	Wed Apr 14 00:36:58 2004
+++ breakpoints.c	Wed Apr 14 00:37:19 2004
@@ -1409,8 +1409,9 @@
 				ptr1 = strchr (ptr, '\n');
 				if (ptr1)
 				{
-					*ptr1++ = '\0';
 					const gchar condition_prefix[] = "\tstop only if ";
+					const gchar ignore_prefix[] = "\tignore next ";
+					*ptr1++ = '\0';
 					if (g_str_has_prefix (ptr1, condition_prefix))
 					{
 						ptr1 += sizeof(condition_prefix) - 1;
@@ -1418,7 +1419,6 @@
 						ptr1 = strchr (cond, '\n');
 						if (ptr1) *ptr1++ = '\0';
 					}
-					const gchar ignore_prefix[] = "\tignore next ";
 					if (g_str_has_prefix (ptr1, ignore_prefix))
 					{
 						ptr1 += sizeof(ignore_prefix) - 1;
