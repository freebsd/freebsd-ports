--- archive.c.orig	Tue Jun 29 05:27:52 1993
+++ archive.c	Tue Dec 28 20:01:38 1999
@@ -326,12 +326,22 @@
 
 void getFileName( char *fileName )
 	{
+#if defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__)
+	int len;
+#endif
 	hprintf( MESG_s_ALREADY_EXISTS_ENTER_NEW_NAME, fileName );
 
 	/* Nasty input routine - should check for illegal chars and suchlike.
 	   Will also overflow if anyone enters more than 16K chars */
 	hflush( stdout );
+#if !defined(__FreeBSD__) && !defined(__OpenBSD__) && !defined(__NetBSD__)
 	hgets( ( char * ) mrglBuffer );
+#else   /* gets depricated in FreeBSD */
+	fgets( mrglBuffer, MAX_PATH, stdin );
+	len = strlen(mrglBuffer);
+	if (mrglBuffer[len - 1] == '\n')
+		mrglBuffer[len - 1] = '\0';
+#endif
 	mrglBuffer[ MAX_PATH - 1 ] = '\0';
 	strcpy( fileName, ( char * ) mrglBuffer );
 
