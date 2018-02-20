--- glob/glob.c.orig	2013-10-20 17:14:38 UTC
+++ glob/glob.c
@@ -203,7 +203,6 @@ my_realloc (p, n)
     return (char *) malloc (n);
   return (char *) realloc (p, n);
 }
-# define	realloc	my_realloc
 # endif /* __SASC */
 #endif /* __GNU_LIBRARY__ || __DJGPP__ */
 
