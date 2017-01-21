--- src/elfcompress.c.orig	2016-12-28 01:32:01.000000000 -0800
+++ src/elfcompress.c	2017-01-18 16:21:03.680565000 -0800
@@ -135,7 +135,10 @@
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
@@ -162,7 +165,7 @@
   struct section_pattern *pattern = patterns;
   while (pattern != NULL)
     {
-      if (fnmatch (pattern->pattern, name, FNM_EXTMATCH) == 0)
+      if (fnmatch (pattern->pattern, name, 0) == 0)
 	return true;
       pattern = pattern->next;
     }
