--- src/prefs.c.orig	Wed Mar 16 19:23:45 2005
+++ src/prefs.c	Wed Mar 16 19:24:06 2005
@@ -2655,7 +2655,7 @@
 	gchar *str = g_hash_table_lookup (prefs_hash, key);
 	if (str)
 	{
-	    *value = atoll (str);
+	    *value = atol (str);
 	    return TRUE;
 	}
     }
