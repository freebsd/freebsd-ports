--- fex/fex/Data_Reader.cpp.orig	2013-10-05 07:19:22.649937270 -0300
+++ fex/fex/Data_Reader.cpp	2013-10-05 07:20:36.384931508 -0300
@@ -732,11 +732,11 @@
 
 blargg_err_t Gzip_File_Reader::read_v( void* p, int s )
 {
-	int result = gzread( file_, p, s );
+	int result = gzread( static_cast<gzFile_s *>(file_), p, s );
 	if ( result != s )
 	{
 		if ( result < 0 )
-			return convert_gz_error( file_ );
+			return convert_gz_error( static_cast<gzFile_s *>(file_) );
 		
 		return blargg_err_file_corrupt;
 	}
@@ -746,8 +746,8 @@
 
 blargg_err_t Gzip_File_Reader::seek_v( int n )
 {
-	if ( gzseek( file_, n, SEEK_SET ) < 0 )
-		return convert_gz_error( file_ );
+	if ( gzseek( static_cast<gzFile_s *>(file_), n, SEEK_SET ) < 0 )
+		return convert_gz_error( static_cast<gzFile_s *>(file_) );
 
 	return blargg_ok;
 }
@@ -756,7 +756,7 @@
 {
 	if ( file_ )
 	{
-		if ( gzclose( file_ ) )
+		if ( gzclose( static_cast<gzFile_s *>(file_) ) )
 			check( false );
 		file_ = NULL;
 	}
