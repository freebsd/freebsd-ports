--- conf.c.orig	Sun Aug  5 23:42:46 2001
+++ conf.c	Sun Aug  5 23:44:29 2001
@@ -39,6 +39,7 @@
 		sscanf( value, "%i", &conf->name );		\
 	}
 
+#ifndef	NOGETOPTLONG
 struct option axel_options[] =
 {
 	/* name			has_arg	flag	val */
@@ -50,6 +51,7 @@
 	{ "version",		0,	NULL,	'V' },
 	{ NULL,			0,	NULL,	0 }
 };
+#endif
 
 int conf_loadfile( conf_t *conf, char *file )
 {
@@ -144,7 +146,17 @@
 	
 	while( 1 )
 	{
-		option = getopt_long( argc, argv, "s:n:NqhV", axel_options, NULL );
+		option = 
+#ifdef NOGETOPTLONG
+			getopt
+#else
+			getopt_long
+#endif
+			( argc, argv, "s:n:NqhV"
+#ifndef    NOGETOPTLONG
+			, axel_options, NULL
+#endif
+			);
 		if( option == -1 )
 			break;
 		
