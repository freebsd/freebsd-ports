--- src/octave/pfsput.cpp.orig	2016-02-12 17:10:27 UTC
+++ src/octave/pfsput.cpp
@@ -52,9 +52,9 @@ DEFUN_DLD( pfsput, args, , helpString)
     return retval;
   }
   
-  Octave_map pfsStream = args(0).map_value();
+  octave_map pfsStream = args(0).map_value();
 
-  Octave_map::const_iterator itFH = pfsStream.seek( "FH" );
+  octave_map::const_iterator itFH = pfsStream.seek( "FH" );
   if( itFH == pfsStream.end() ||
     !pfsStream.contents( itFH )(0).is_real_scalar() )
   {
@@ -65,7 +65,7 @@ DEFUN_DLD( pfsput, args, , helpString)
 
   // Check mode
   {                             
-    Octave_map::const_iterator itMode = pfsStream.seek( "MODE" );
+    octave_map::const_iterator itMode = pfsStream.seek( "MODE" );
     if( itMode == pfsStream.end() || !pfsStream.contents( itMode )(0).is_string() )
     {
       error( SCRIPT_NAME ": MODE field missing in the structure or it has wrong type");
@@ -80,8 +80,8 @@ DEFUN_DLD( pfsput, args, , helpString)
   // Get width & height
   int width, height;
   {                             
-    Octave_map::const_iterator itCols = pfsStream.seek( "columns" );
-    Octave_map::const_iterator itRows = pfsStream.seek( "rows" );
+    octave_map::const_iterator itCols = pfsStream.seek( "columns" );
+    octave_map::const_iterator itRows = pfsStream.seek( "rows" );
     if( itCols == pfsStream.end() || itRows == pfsStream.end() ||
       !pfsStream.contents( itCols )(0).is_real_scalar() ||
       !pfsStream.contents( itRows )(0).is_real_scalar() )
@@ -94,9 +94,9 @@ DEFUN_DLD( pfsput, args, , helpString)
   }
 
   // Get channels
-  Octave_map channels;
+  octave_map channels;
   {
-    Octave_map::const_iterator itChannels = pfsStream.seek( "channels" );
+    octave_map::const_iterator itChannels = pfsStream.seek( "channels" );
     if( itChannels == pfsStream.end() ||
       !pfsStream.contents( itChannels )(0).is_map() )
     {
@@ -111,7 +111,7 @@ DEFUN_DLD( pfsput, args, , helpString)
     pfs::Frame *frame = ctx.createFrame( width, height );
 
     // For each channel in the 'channels' map
-    for( Octave_map::iterator itCh = channels.begin(); itCh != channels.end(); itCh++ ) {
+    for( octave_map::iterator itCh = channels.begin(); itCh != channels.end(); itCh++ ) {
       std::string channelName = channels.key(itCh);
 
       if( !channels.contents( itCh )(0).is_real_matrix() ) {
@@ -135,15 +135,15 @@ DEFUN_DLD( pfsput, args, , helpString)
 
     // Copy frame tags
     {
-      Octave_map::const_iterator itTags = pfsStream.seek( "tags" );
+      octave_map::const_iterator itTags = pfsStream.seek( "tags" );
       if( itTags != pfsStream.end() ) {
         if( !pfsStream.contents( itTags )(0).is_map() )
         {
           throw pfs::Exception( "'tags' field must be a structure" );  
         }
         
-        Octave_map tags = pfsStream.contents( itTags )(0).map_value();
-        for( Octave_map::iterator itTag = tags.begin(); itTag != tags.end(); itTag++ ) {
+        octave_map tags = pfsStream.contents( itTags )(0).map_value();
+        for( octave_map::iterator itTag = tags.begin(); itTag != tags.end(); itTag++ ) {
           std::string tagName = tags.key(itTag);
 
           if( !tags.contents( itTag )(0).is_string() ) 
@@ -156,14 +156,14 @@ DEFUN_DLD( pfsput, args, , helpString)
 
     // Copy channel tags
     {
-      Octave_map::const_iterator itChTags = pfsStream.seek( "channelTags" );
+      octave_map::const_iterator itChTags = pfsStream.seek( "channelTags" );
       if( itChTags != pfsStream.end() ) {
         if( !pfsStream.contents( itChTags )(0).is_map() )
         {
           throw pfs::Exception( "'channelTags' field must be a structure" );  
         }
-        Octave_map tagChannels = pfsStream.contents( itChTags )(0).map_value();
-        for( Octave_map::iterator itCh = tagChannels.begin(); itCh != tagChannels.end(); itCh++ ) {
+        octave_map tagChannels = pfsStream.contents( itChTags )(0).map_value();
+        for( octave_map::iterator itCh = tagChannels.begin(); itCh != tagChannels.end(); itCh++ ) {
           std::string channelName = tagChannels.key(itCh);
           if( !tagChannels.contents( itCh )(0).is_map() ) {
             throw pfs::Exception( "each channelTags file must be a structure" );  
@@ -173,8 +173,8 @@ DEFUN_DLD( pfsput, args, , helpString)
             throw pfs::Exception( "can not set channel tag if channel is missing" );
           }
           
-          Octave_map tags = tagChannels.contents( itCh )(0).map_value();
-          for( Octave_map::iterator itTag = tags.begin(); itTag != tags.end(); itTag++ ) {
+          octave_map tags = tagChannels.contents( itCh )(0).map_value();
+          for( octave_map::iterator itTag = tags.begin(); itTag != tags.end(); itTag++ ) {
             std::string tagName = tags.key(itTag);
             if( !tags.contents( itTag )(0).is_string() ) 
               throw pfs::Exception( "all channel tags must be given as strings" );
