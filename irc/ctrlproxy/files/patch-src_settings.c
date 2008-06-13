
$FreeBSD$

--- src/settings.c.orig
+++ src/settings.c
@@ -1055,7 +1055,7 @@
 	}
 
     if (g_key_file_has_key(kf, "global", "learn-nickserv", NULL))
-		cfg->learn_nickserv = g_key_file_get_boolean(kf, "global", "learn-nicksev", NULL);
+		cfg->learn_nickserv = g_key_file_get_boolean(kf, "global", "learn-nickserv", NULL);
     else 
 	    cfg->learn_nickserv = TRUE;
 
