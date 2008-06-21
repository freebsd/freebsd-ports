--- ./SequenceReader/SequenceReaderMulti.cpp.orig	2004-03-01 13:51:30.000000000 -0300
+++ ./SequenceReader/SequenceReaderMulti.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -166,7 +166,7 @@
   {
     if (thisReader_->allSeqsRead_)
     {
-      if ( currentSeqNum_ <= thisReader_->size_ )
+      if ( currentSeqNum_ <= (SequenceNumber)thisReader_->size_ )
       {
 	//	assert( thisReader_->ptr_->findSequence( currentSeqNum_ ) == true );
 	lastSequenceNumber_ = --seqNum; // last read = 1 behind current
@@ -240,7 +240,7 @@
     for ( vector<SeqReaderInfo>::iterator i = allReaders_.begin(); 
           i != allReaders_.end(); i++ )
     {
-      if ( seqNum <= i->size_ ) { thisReader_ = i; break; } // %%%%%
+      if ( seqNum <= (SequenceNumber)i->size_ ) { thisReader_ = i; break; } // %%%%%
       seqNum -= i->size_;
     } // ~for i
 
@@ -276,7 +276,8 @@
   {
     DEBUG_L2( "SequenceReaderMulti::getNextSequence" );
 
-    int numInLast;
+    int numInLast = -1;  // Initialized to avoid -Wall possibly used before initialized warning.
+                         // The algorithm should be checked carefully.
 
     while 
       (    ( thisReader_ 
