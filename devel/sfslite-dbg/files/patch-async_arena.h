--- async/arena.h	2005-11-01 18:20:29.000000000 +0200
+++ async/arena.h_new	2007-07-07 00:36:09.000000000 +0300
@@ -61,7 +61,7 @@
 #ifdef DMALLOC
   char *_strdup_leap (const char *, int, const char *str)
     { return strcpy ((char *) alloc (1 + strlen (str), 1), str); }
-  char *dmalloc_strdup (const char *, int, const char *str, int)
+  char *dmalloc_strndup (const char *, int, const char *str, int, int)
     { return strcpy ((char *) alloc (1 + strlen (str), 1), str); }
 #endif /* DMALLOC */
 
