--- utils.c.orig	2000-07-31 22:37:23 UTC
+++ utils.c
@@ -12,25 +12,6 @@ static char rcsid[] = "@(#)$Id: utils.c,v 1.14 2000/07
 
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
