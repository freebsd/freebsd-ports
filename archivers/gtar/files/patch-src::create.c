
$FreeBSD$

--- src/create.c	2002/06/01 21:08:46	1.1
+++ src/create.c	2002/06/01 21:09:16
@@ -1473,7 +1473,7 @@
 	  if (linklen != current_stat.st_size || linklen + 1 == 0)
 	    xalloc_die ();
 	  buffer = (char *) alloca (linklen + 1);
-	  size = readlink (p, buffer, linklen + 1);
+	  size = readlink (p, buffer, linklen);
 	  if (size < 0)
 	    {
 	      if (ignore_failed_read_option)
