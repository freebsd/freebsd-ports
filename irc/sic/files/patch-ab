--- utils.c.orig	Sun Mar 31 19:32:45 2002
+++ utils.c	Sun Mar 31 19:32:55 2002
@@ -12,25 +12,6 @@
 
 #include "os.h"
 
-/* strcasestr: case insensitive version of strstr() */
-char *
-strcasestr(s1, s2)
-  char    *s1, *s2;
-{
-  int	len;
-
-  assert( s1 && s2 );
-
-  len = strlen(s2);
-  while (*s1)
-    {
-      if (!strncasecmp(s1, s2, len))
-	  return s1;
-      s1++;
-    }
-  return NULL;
-}
-
 /* match: some lame version
  *	returns 0 if no match.
  */
