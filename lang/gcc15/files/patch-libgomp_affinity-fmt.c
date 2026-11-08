--- libgomp/affinity-fmt.c.orig	2025-08-08 06:51:45 UTC
+++ libgomp/affinity-fmt.c
@@ -327,7 +327,7 @@ gomp_display_affinity (char *buffer, size_t size,
 	      }
 	  if (c == '{')
 	    {
-	      char *q = strchr (p + 1, '}');
+	      const char *q = strchr (p + 1, '}');
 	      if (q)
 		gomp_fatal ("unsupported long type name '%.*s' in affinity "
 			    "format", (int) (q - (p + 1)), p + 1);
