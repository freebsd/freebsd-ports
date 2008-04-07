--- src/lib/FLACFile.cpp.orig	2008-03-27 21:03:52.000000000 +0100
+++ src/lib/FLACFile.cpp	2008-03-27 21:05:03.000000000 +0100
@@ -164,15 +164,13 @@ void FLACFile_real::load( string sFilena
 	}
 
 	set_metadata_ignore_all();
-	set_filename( sFilename.c_str() );
 
-	State s=init();
-	if( s != FLAC__FILE_DECODER_OK ) {
+	if( FLAC__STREAM_DECODER_INIT_STATUS_OK != init( sFilename.c_str() ) ) {
 		errorLog( "[load] Error in init()" );
 	}
 
-	if ( process_until_end_of_file() == false ) {
-		errorLog( "[load] Error in process_until_end_of_file()" );
+	if ( process_until_end_of_stream() == false ) {
+		errorLog( "[load] Error in process_until_end_of_stream()" );
 	}
 }
 
