--- src/pfsview/pfsview_widget.cpp.orig	2011-04-30 14:01:17.000000000 +0000
+++ src/pfsview/pfsview_widget.cpp	2014-02-20 19:04:01.566588122 +0000
@@ -142,7 +142,7 @@
     // Chose first available channel
     pfs::ChannelIterator *it = frame->getChannels();
     if( !it->hasNext() )      // TODO: failover
-      throw new pfs::Exception( "No channels available!" );
+      throw pfs::Exception( "No channels available!" );
     visibleChannel = it->getNext()->getName();
   } else if( visibleChannel != COLOR_CHANNELS ) {
     // Get a new pointer, as the old frame object
@@ -335,8 +335,8 @@
   assert( !color || (color && B != NULL) );
 
   
-  float lutPixFloor[257*2];
-  QRgb lutPixel[257*2];
+  float lutPixFloor[257*2+1];
+  QRgb lutPixel[257*2+1];
   int lutSize;
   if( !color && ( negativeTreatment == NEGATIVE_GREEN_SCALE ||
         negativeTreatment == NEGATIVE_ABSOLUTE ) ) { // Handle negative numbers
