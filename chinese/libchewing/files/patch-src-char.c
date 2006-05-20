--- src/char.c.orig	Mon May 15 14:49:43 2006
+++ src/char.c	Sun May 21 00:14:41 2006
@@ -126,7 +126,7 @@
 
 	fgettab( buf, 1000, dictfile );
 	/* only read 6 bytes to wrd_ptr->word avoid buffer overflow */
-	sscanf( buf, "%hu %6s", &sh, wrd_ptr->word );
+	sscanf( buf, "%hu %6[^ ]", &sh, wrd_ptr->word );
 	assert( wrd_ptr->word != NULL );
 }
 
