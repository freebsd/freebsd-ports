
$FreeBSD$

--- src/names.c.orig
+++ src/names.c
@@ -1012,11 +1012,10 @@
       if (p[0] == '.' && p[1] == '.' && (ISSLASH (p[2]) || !p[2]))
 	return 1;
 
-      do
+      while (! ISSLASH (*p))
 	{
 	  if (! *p++)
 	    return 0;
 	}
-      while (! ISSLASH (*p));
     }
 }
