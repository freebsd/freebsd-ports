--- crypt/keymgmt.c.orig	1993-08-17 21:56:14 UTC
+++ crypt/keymgmt.c
@@ -495,11 +495,24 @@ BOOLEAN getKey( const BOOLEAN isPemKey, 
 	FD keyFileFD, savedInFD = getInputFD();
 	BOOLEAN matched, firstTime = TRUE;
 	char *matchID, firstChar;
-	char *keyFilePath;
+	char *keyFilePath, *s;
 	int userIDlength, i;
+#ifdef __UNIX__
+	char *h, buf[ MAX_PATH ];
+#endif
 
+	if ((s = getenv( PGPPATH )) == NULL)
+#ifdef __UNIX__
+		if ((h = getenv( "HOME" )) != NULL) {
+			strcpy(buf, h);
+			strcat(buf, "/.pgp");
+			s = buf;
+		}
+#else
+		;
+#endif
 	/* Use the keyID to get the public key from a key file */
-	keyFilePath = getFirstKeyPath( getenv( PGPPATH ), keyFileName );
+	keyFilePath = getFirstKeyPath( s, keyFileName );
 	while( keyFilePath != NULL )
 		{
 		/* Open key file */
