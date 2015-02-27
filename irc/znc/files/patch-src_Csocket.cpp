--- src/Csocket.cpp.orig	2014-05-08 22:21:25.000000000 +0200
+++ src/Csocket.cpp	2015-02-27 12:48:58.701917721 +0100
@@ -555,22 +555,6 @@
 	}
 #endif /* _WIN32 */
 
-	COMP_METHOD *cm = NULL;
-
-	if( CT_ZLIB & eCompressionType )
-	{
-		cm = COMP_zlib();
-		if( cm )
-			SSL_COMP_add_compression_method( CT_ZLIB, cm );
-	}
-
-	if( CT_RLE & eCompressionType )
-	{
-		cm = COMP_rle();
-		if( cm )
-			SSL_COMP_add_compression_method( CT_RLE, cm );
-	}
-
 	// setting this up once in the begining
 	g_iCsockSSLIdx = SSL_get_ex_new_index( 0, ( void * )"CsockGlobalIndex", NULL, NULL, NULL );
 
