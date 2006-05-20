--- src/dict.c.orig	Mon May 15 14:49:43 2006
+++ src/dict.c	Sun May 21 00:14:29 2006
@@ -101,7 +101,7 @@
 	char buf[ 1000 ];
 
 	fgettab( buf, 1000, dictfile );
-	sscanf( buf, "%s %d", phr_ptr->phrase, &( phr_ptr->freq ) );
+	sscanf( buf, "%[^ ] %d", phr_ptr->phrase, &( phr_ptr->freq ) );
 }
 
 int GetPhraseFirst( Phrase *phr_ptr, int phone_phr_id )
