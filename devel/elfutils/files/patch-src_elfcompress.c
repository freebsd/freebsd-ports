--- src/elfcompress.c.orig	2020-03-30 12:17:45 UTC
+++ src/elfcompress.c
@@ -135,7 +135,10 @@ parse_opt (int key, char *arg __attribute__ ((unused))
       if (type == T_UNSET)
 	type = T_COMPRESS_ZLIB;
       if (patterns == NULL)
-	add_pattern (".?(z)debug*");
+	{
+	  add_pattern (".debug*");
+	  add_pattern (".zdebug*");
+	}
       break;
 
     case ARGP_KEY_NO_ARGS:
@@ -162,7 +165,7 @@ section_name_matches (const char *name)
   struct section_pattern *pattern = patterns;
   while (pattern != NULL)
     {
-      if (fnmatch (pattern->pattern, name, FNM_EXTMATCH) == 0)
+      if (fnmatch (pattern->pattern, name, 0) == 0)
 	return true;
       pattern = pattern->next;
     }
