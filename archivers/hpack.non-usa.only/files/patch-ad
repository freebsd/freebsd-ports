--- keycvt/keycvt.c.orig	Fri Aug 13 15:06:28 1993
+++ keycvt/keycvt.c	Tue Dec 28 20:01:38 1999
@@ -582,11 +582,21 @@
 
 static void getPassword( void )
 	{
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+	int len;
+#endif
 	puts( "Please enter password for this private key." );
 	puts( "Warning: Password will be echoed to screen!" );
 	printf( "Password: " );
 	fflush( stdout );
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 	gets( password );
+#else   /* gets depricated in FreeBSD */
+	fgets( password, sizeof(password), stdin);
+	len = strlen(password);
+	if (password[len - 1] == '\n')
+		password[len - 1] = '\0';
+#endif
 	}
 
 void initCrypt( void )
@@ -1020,27 +1030,46 @@
 
 	/* Try and find the PGP seed file */
 	if( ( pgpPath = getenv( "PGPPATH" ) ) == NULL )
+#ifdef __UNIX__
+		if( ( pgpPath = getenv( "HOME" ) ) != NULL ) {
+			strcpy( tempFileName, pgpPath );
+			strcat( tempFileName, "/.pgp");
+			pgpPath = tempFileName;
+		}
+		else
+#endif
 		pgpPath = "";
 	pathLen = strlen( pgpPath );
+#ifdef __UNIX__
+	if (pgpPath != tempFileName)
+#endif
 	strcpy( tempFileName, pgpPath );
 #if defined( __ARC__ )
-	if( pathLen && tempFileName[ pathLen - 1 ] != '.' )
+	if( pathLen && tempFileName[ pathLen - 1 ] != '.' ) {
 		/* Add directory seperator if necessary */
 		tempFileName[ pathLen++ ] = '.';
+		tempFileName[ pathLen ] = '\0';
+	}
 	strcat( tempFileName, "randseed" );
 #elif defined( __AMIGA__ )
-	if( pathLen && ( ch = tempFileName[ pathLen - 1 ] ) != ':' && ch != '/' )
+	if( pathLen && ( ch = tempFileName[ pathLen - 1 ] ) != ':' && ch != '/' ) {
 		/* Add directory seperator if necessary */
 		tempFileName[ pathLen++ ] = '/';
+		tempFileName[ pathLen ] = '\0';
+	}
 	strcat( tempFileName, "randseed.bin" );
 #else
-	if( pathLen && ( ch = tempFileName[ pathLen - 1 ] ) != '\\' && ch != '/' )
+	if( pathLen && ( ch = tempFileName[ pathLen - 1 ] ) != '\\' && ch != '/' ) {
 		/* Add directory seperator if necessary */
 		tempFileName[ pathLen++ ] = '/';
+		tempFileName[ pathLen ] = '\0';
+	}
 	strcat( tempFileName, "randseed.bin" );
 #endif /* __ARC__ */
-	if( ( inFilePtr = fopen( tempFileName, "rb" ) ) == NULL )
+	if( ( inFilePtr = fopen( tempFileName, "rb" ) ) == NULL ) {
+		perror( tempFileName );
 		puts( "Cannot find PGP seed file, HPACK seed file not created" );
+	}
 	else
 		{
 		/* See if the output file exists */
