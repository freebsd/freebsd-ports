--- imap/browse.c.orig	Wed Nov  5 09:41:36 2003
+++ imap/browse.c	Sat Jul  1 20:47:53 2006
@@ -452,7 +452,7 @@
 	    if (*s == '\"')
 	    {
 	      s++;
-	      while (*s && *s != '\"') 
+	      while (*s && *s != '\"' && n < sizeof (ns) - 1) 
 	      {
 		if (*s == '\\')
 		  s++;
@@ -463,12 +463,14 @@
 		s++;
 	    }
 	    else
-	      while (*s && !ISSPACE (*s)) 
+	      while (*s && !ISSPACE (*s) && n < sizeof (ns) - 1)
 	      {
 		ns[n++] = *s;
 		s++;
 	      }
 	    ns[n] = '\0';
+	    if (n == sizeof (ns) - 1)
+	      dprint (1, (debugfile, "browse_get_namespace: too long: [%s]\n", ns));
 	    /* delim? */
 	    s = imap_next_word (s);
 	    /* delimiter is meaningless if namespace is "". Why does
