--- hdrmacro.c.orig	2014-08-07 15:19:17.000000000 +0200
+++ hdrmacro.c	2014-08-07 15:23:19.000000000 +0200
@@ -39,8 +39,6 @@
  *		just to invoke a rule.
  */
 
-static LIST *header_macros1( LIST *l, char *file, int rec, regexp *re[] );
-
 /* this type is used to store a dictionary of file header macros */
 typedef struct header_macro
 {
@@ -60,11 +58,9 @@
 void
 macro_headers( TARGET *t )
 {
-	LIST	*hdrrule;
 	regexp	*re;
 	FILE	*f;
 	char	buf[ 1024 ];
-	int	i;
 
     if ( DEBUG_HEADER )
       printf( "macro header scan for %s\n", t->name );
