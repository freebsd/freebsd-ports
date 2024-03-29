--- lib/glob.c.orig	2020-01-03 07:11:27 UTC
+++ lib/glob.c
@@ -203,7 +203,6 @@ my_realloc (p, n)
     return (char *) malloc (n);
   return (char *) realloc (p, n);
 }
-# define	realloc	my_realloc
 # endif /* __SASC */
 #endif /* __GNU_LIBRARY__ || __DJGPP__ */
 
