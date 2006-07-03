--- imap/browse.c.orig	Tue Feb 26 10:38:56 2002
+++ imap/browse.c	Sat Jul  1 20:18:02 2006
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
