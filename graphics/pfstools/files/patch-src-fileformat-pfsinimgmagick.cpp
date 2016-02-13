--- src/fileformat/pfsinimgmagick.cpp.orig	2008-10-03 19:07:34 UTC
+++ src/fileformat/pfsinimgmagick.cpp
@@ -108,6 +108,7 @@ void readFrames( int argc, char* argv[] 
     if( ff.fh == NULL ) break; // No more frames
     it.closeFrameFile( ff );
 
+    Magick::InitializeMagick(*argv);
     VERBOSE_STR << "reading file '" << ff.fileName << "'" << std::endl;
     Magick::Image imImage( ff.fileName );
 
@@ -172,7 +173,7 @@ void readFrames( int argc, char* argv[] 
     frame->getTags()->setString( "FILE_NAME", fileNameTag );
  
     char strbuf[3];
-    snprintf( strbuf, 3, "%d", imImage.depth() );
+    snprintf( strbuf, 3, "%lu", imImage.depth() );
     frame->getTags()->setString("BITDEPTH", strbuf );    
    
     pfsio.writeFrame( frame, stdout );
