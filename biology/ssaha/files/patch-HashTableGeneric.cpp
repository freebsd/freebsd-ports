--- ./HashTable/HashTableGeneric.cpp.orig	2005-06-21 05:48:27.000000000 -0300
+++ ./HashTable/HashTableGeneric.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -63,18 +63,18 @@
 ( ostream& monitoringStream,
   const string& name,
   Allocator<PositionInHitList>& arrayAllocator ) : 
-  isInitialized_( false ), 
-  monitoringStream_( monitoringStream ),
   name_( name ),
-  bitsPerSymbol_( gBaseBits ), // default: may be overwritten in subclass ctor
+  isInitialized_( false ), 
   maxNumHits_( defaultMaxNumHits ),
+  bitsPerSymbol_( gBaseBits ), // default: may be overwritten in subclass ctor
   hitListFormat_( gNotSpecified ),
+  monitoringStream_( monitoringStream ),
   pArrayAllocator_
   ( arrayAllocator.clone(&pWordPositionInHitList_,
 			 name+(string)".head",
 			 monitoringStream_) ),
-  pSequenceSizes_(NULL),
-  pNameReader_(NULL)
+  pNameReader_(NULL),
+  pSequenceSizes_(NULL)
   {
     monitoringStream_ << "constructing HashTableGeneric\n";
     if (name_=="")
@@ -290,7 +290,7 @@
   WordSequence thisSeq;
     
   // NB sequences are numbered 1...n not 0...n-1
-  for ( unsigned int i(1); i <= numSeqs ; i++ )
+  for ( int i(1); i <= numSeqs ; i++ )
   {
     if( sequenceReader.getNextSequence( thisSeq, wordLength_) == -1 ) 
     {
@@ -973,10 +973,10 @@
 
 SequenceAdapterWithOverlap::SequenceAdapterWithOverlap
 ( int bitsPerSymbol, int wordLength, int stepLength ) :
+SequenceAdapter(),
 bitsPerSymbol_( bitsPerSymbol ), 
 wordLength_( wordLength ), 
-stepLength_( stepLength ),
-SequenceAdapter() 
+stepLength_( stepLength )
 {
 
   maskLeft_  = new Word[ wordLength_ ];
