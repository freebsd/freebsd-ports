--- cli.c.orig	1993-09-05 03:23:48 UTC
+++ cli.c
@@ -724,12 +724,18 @@ static BOOLEAN checkStealthMode( char *a
 
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
