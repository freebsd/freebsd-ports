--- src/pfsview/pfsview_widget.cpp.orig	2018-01-19 06:59:44 UTC
+++ src/pfsview/pfsview_widget.cpp
@@ -147,7 +147,7 @@ void PFSViewWidget::setFrame( pfs::Frame
     // Chose first available channel
     pfs::ChannelIterator *it = frame->getChannels();
     if( !it->hasNext() )      // TODO: failover
-      throw new pfs::Exception( "No channels available!" );
+      throw pfs::Exception( "No channels available!" );
     visibleChannel = it->getNext()->getName();
   } else if( visibleChannel != COLOR_CHANNELS ) {
     // Get a new pointer, as the old frame object
@@ -340,8 +340,8 @@ static void mapFrameToImage( pfs::Array2
   assert( !color || (color && B != NULL) );
 
   
-  float lutPixFloor[257*2];
-  QRgb lutPixel[257*2];
+  float lutPixFloor[257*2+1];
+  QRgb lutPixel[257*2+1];
   int lutSize;
   if( !color && ( negativeTreatment == NEGATIVE_GREEN_SCALE ||
         negativeTreatment == NEGATIVE_ABSOLUTE ) ) { // Handle negative numbers
