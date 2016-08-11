--- language/language.c.orig	1993-09-23 02:23:20 UTC
+++ language/language.c
@@ -188,7 +188,7 @@ void showHelp( void )
 				/* Process user response */
 				response = hgetch();
 				response = toupper( response );	/* Damn macros */
-				blankLine( screenWidth );
+				blankLine( screenWidth - 1 );
 				if( response == RESPONSE_QUIT )
 					return;
 				lineNo -= ( response == ' ' ) ? screenHeight : 1;
@@ -268,6 +268,9 @@ int initMessages( const char *path, cons
 	if( ( inFD = hopen( fileNamePtr, O_RDONLY | S_DENYWR | A_RANDSEQ ) ) == ERROR )
 		return( ERROR );
 #elif defined( __UNIX__ )
+	fileNamePtr = getFirstKeyPath( "%%PREFIX%%/lib/hpack", DATA_FILENAME );
+	if( ( inFD = hopen( fileNamePtr, O_RDONLY | S_DENYWR | A_RANDSEQ ) ) != ERROR )
+		goto found;
 	/* Build path to language file and try and process it */
 	fileNamePtr = getFirstKeyPath( getenv( "PATH" ), DATA_FILENAME );
 	while( fileNamePtr != NULL )
@@ -290,6 +293,9 @@ int initMessages( const char *path, cons
 			return( ERROR );		/* Couldn't find/open input file */
 		}
 #endif /* System-specific handling of how to find language defn.file */
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+found:
+#endif
 	setInputFD( inFD );
 	resetFastIn();
 
