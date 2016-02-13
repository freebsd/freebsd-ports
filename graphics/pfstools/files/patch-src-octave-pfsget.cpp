--- src/octave/pfsget.cpp.orig	2016-02-12 17:10:27 UTC
+++ src/octave/pfsget.cpp
@@ -52,9 +52,9 @@ DEFUN_DLD( pfsget, args, , helpString)
     return retval;
   }
 
-  Octave_map pfsStream = args(0).map_value();
+  octave_map pfsStream = args(0).map_value();
 
-  Octave_map::const_iterator itFH = pfsStream.seek( "FH" );
+  octave_map::const_iterator itFH = pfsStream.seek( "FH" );
   if( itFH == pfsStream.end() ||
     !pfsStream.contents( itFH )(0).is_real_scalar() )
   {
@@ -63,7 +63,7 @@ DEFUN_DLD( pfsget, args, , helpString)
   }  
   FILE *fh = (FILE*)((long)(pfsStream.contents( itFH )(0).double_value()));
 
-  Octave_map::const_iterator itMode = pfsStream.seek( "MODE" );
+  octave_map::const_iterator itMode = pfsStream.seek( "MODE" );
   if( itMode == pfsStream.end() || !pfsStream.contents( itMode )(0).is_string() )
   {
     error( SCRIPT_NAME ": MODE field missing in the structure or it has wrong type");
@@ -95,7 +95,7 @@ DEFUN_DLD( pfsget, args, , helpString)
     
       // Add channels as matrices to pfs stream struct
       {
-        Octave_map channels;
+        octave_scalar_map channels;
         
         pfs::ChannelIteratorPtr cit( frame->getChannelIterator() );
         while( cit->hasNext() ) {
@@ -115,7 +115,7 @@ DEFUN_DLD( pfsget, args, , helpString)
 
       //Add tags
       {
-        Octave_map tags;
+        octave_scalar_map tags;
         
         pfs::TagIteratorPtr it( frame->getTags()->getIterator() );        
         while( it->hasNext() ) {
@@ -124,14 +124,14 @@ DEFUN_DLD( pfsget, args, , helpString)
         }
         pfsStream.assign( "tags", tags );
         
-        Octave_map channelTagList;
+        octave_scalar_map channelTagList;
 
         //Copy all channel tags
         pfs::ChannelIteratorPtr cit( frame->getChannelIterator() );
         while( cit->hasNext() ) {
           pfs::Channel *ch = cit->getNext();
 
-          Octave_map channelTags;
+          octave_scalar_map channelTags;
           
           pfs::TagIteratorPtr tit( ch->getTags()->getIterator() );        
           while( tit->hasNext() ) {
