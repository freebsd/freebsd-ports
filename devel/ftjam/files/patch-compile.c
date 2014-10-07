--- compile.c.orig	2014-08-07 15:35:58.000000000 +0200
+++ compile.c	2014-08-07 15:36:52.000000000 +0200
@@ -371,6 +371,8 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)jmp;
+
 	/* voodoo 1 means: s is a copyable string */
 	const char *s = parse->string;
 	return var_expand( L0, s, s + strlen( s ), args, 1 );
@@ -434,6 +436,10 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)parse;
+	(void)args;
+	(void)jmp;
+
 	return L0;
 }
 
@@ -692,6 +698,9 @@
 	LOL	*args,
 	int	*jmp )
 {
+	(void)args;
+	(void)jmp;
+
 	RULE	*rule = bindrule( parse->string );
 	LIST	*params = 0;
 	PARSE	*p;
