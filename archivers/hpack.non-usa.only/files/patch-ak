--- cli.c.orig	Sat Sep  4 22:23:48 1993
+++ cli.c	Tue Dec 28 20:01:38 1999
@@ -724,12 +724,18 @@
 
 void doConfigFile( void )
 	{
-	char *configFileName;
+	char *configFileName, *s;
 	FD configFileFD;
 	WORD oldFlags = flags;
 
+	if (( s = getenv( HPACKPATH )) == NULL)
+#ifdef __UNIX__
+		s = "%%PREFIX%%/etc:%%PREFIX%%/lib/hpack";
+#else
+		;
+#endif
 	/* Build path to config file and try and process it */
-	configFileName = getFirstKeyPath( getenv( HPACKPATH ), CONFIGFILENAME );
+	configFileName = getFirstKeyPath( s, CONFIGFILENAME );
 	while( configFileName != NULL )
 		{
 		/* Try and read the seed from the seedfile */
