--- builtins.c.orig	2006-06-05 12:52:18.000000000 +0200
+++ builtins.c	2014-08-07 15:35:40.000000000 +0200
@@ -134,9 +134,10 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)jmp;
+
 	LIST *targets = lol_get( args, 0 );
 	LIST *sources = lol_get( args, 1 );
-	int which = parse->num;
 	LIST *l;
 
 	for( l = targets; l; l = list_next( l ) )
@@ -173,6 +174,9 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)parse;
+	(void)jmp;
+
 	list_print( lol_get( args, 0 ) );
 	printf( "\n" );
 	return L0;
@@ -191,6 +195,9 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)parse;
+	(void)jmp;
+
 	list_print( lol_get( args, 0 ) );
 	printf( "\n" );
 	exit( EXITBAD ); /* yeech */
@@ -210,6 +217,9 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)parse;
+	(void)jmp;
+
 	LIST *l = lol_get( args, 0 );
 
 	for( ; l; l = list_next( l ) )
@@ -234,6 +244,9 @@
 	int	status,
 	time_t	time )
 {
+	(void)status;
+	(void)time;
+
 	struct globbing *globbing = (struct globbing *)closure;
 	LIST		*l;
 	PATHNAME	f;
@@ -260,6 +273,9 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)parse;
+	(void)jmp;
+
 	LIST *l = lol_get( args, 0 );
 	LIST *r = lol_get( args, 1 );
 
@@ -284,6 +300,9 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)parse;
+	(void)jmp;
+
 	LIST *l, *r;
 	LIST *result = 0;
 
@@ -332,19 +351,22 @@
     LOL      *args,
     int      *jmp )
 {
-  LIST*  l = lol_get( args, 0 );
+	(void)parse;
+	(void)jmp;
 
-  for ( ; l; l = list_next(l) )
-  {
-    TARGET*  t = bindtarget( l->string );
+	LIST*  l = lol_get( args, 0 );
 
-    /* scan file for header filename macro definitions */
-    if ( DEBUG_HEADER )
-      printf( "scanning '%s' for header file macro definitions\n",
-              l->string );
+	for ( ; l; l = list_next(l) )
+	{
+		TARGET*  t = bindtarget( l->string );
 
-    macro_headers( t );
-  }
+		/* scan file for header filename macro definitions */
+		if ( DEBUG_HEADER )
+			printf( "scanning '%s' for header file macro definitions\n",
+					l->string );
 
-  return L0;
+		macro_headers( t );
+	}
+
+	return L0;
 }
