--- mysql-query-browser/source/linux/gtksourceview/gtksourceview/gnu-regex/regcomp.c.orig	Sun Apr  9 00:37:59 2006
+++ mysql-query-browser/source/linux/gtksourceview/gtksourceview/gnu-regex/regcomp.c	Sun Apr  9 00:39:42 2006
@@ -451,18 +451,6 @@
   if (ret == REG_ERPAREN)
     ret = REG_EPAREN;
 
-  /* We have already checked preg->fastmap != NULL.  */
-  if (BE (ret == REG_NOERROR, 1))
-    /* Compute the fastmap now, since regexec cannot modify the pattern
-       buffer.  This function nevers fails in this implementation.  */
-    (void) re_compile_fastmap (preg);
-  else
-    {
-      /* Some error occurred while compiling the expression.  */
-      re_free (preg->fastmap);
-      preg->fastmap = NULL;
-    }
-
   return (int) ret;
 }
 #ifdef _LIBC
