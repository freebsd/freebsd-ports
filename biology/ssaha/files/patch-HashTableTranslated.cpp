--- ./HashTable/HashTableTranslated.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./HashTable/HashTableTranslated.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -50,9 +50,9 @@
  		   Allocator<PositionPacked>& hitListAllocator,
 		   Allocator<PositionInHitList>& arrayAllocator 
 		   ):
-  queryFrame_(0),
   HashTablePacked( monitoringStream, name, 
-		   hitListAllocator, arrayAllocator  ) 
+		   hitListAllocator, arrayAllocator  ), 
+  queryFrame_(0)
 {
   hitListFormat_ = g32BitPackedProtein;
   bitsPerSymbol_ = gResidueBits;
@@ -135,12 +135,12 @@
   Allocator<PositionPacked>& hitListAllocator,
   Allocator<PositionInHitList>& arrayAllocator 
   ):
+  HashTablePacked( monitoringStream, name, 
+		     hitListAllocator, arrayAllocator  ),
+  codonEncoder_(5),
   queryFrame_(0),
   queryMult_(1),
-  codonEncoder_(5),
-  pMatchSequence_( &HashTablePackedProtein::matchSequenceProtein ),
-  HashTablePacked( monitoringStream, name, 
-		     hitListAllocator, arrayAllocator  ) 
+  pMatchSequence_( &HashTablePackedProtein::matchSequenceProtein )
 {
     hitListFormat_ = g32BitPackedProtein;
     bitsPerSymbol_ = gResidueBits;
@@ -249,14 +249,14 @@
   Allocator<PositionPacked>& hitListAllocator,
   Allocator<PositionInHitList>& arrayAllocator
   ) :
+  HashTableGeneric( monitoringStream, name, arrayAllocator ),
   hashFwd_( monitoringStream, name+(string)"_fwd", 
 	    hitListAllocator, arrayAllocator ),
   hashRev_( monitoringStream, name+(string)"_rev", 
 	    hitListAllocator, arrayAllocator ),
   pHash_(&hashFwd_),
   codonEncoder_(5),
-  pMatchSequence_( &HashTableTranslated::matchSequenceProtein ),
-  HashTableGeneric( monitoringStream, name, arrayAllocator ) 
+  pMatchSequence_( &HashTableTranslated::matchSequenceProtein )
 {
   bitsPerSymbol_=gResidueBits;
   hitListFormat_ = gTranslated;
@@ -344,8 +344,8 @@
 
     // Change encoding mode
     SequenceReaderModeFlagReplace mode('X');
-    assert(ttCodon['X']==ttProtein['X']);
-    assert(ttCodon['X']!=nv);
+    assert(ttCodon[(int)'X']==ttProtein[(int)'X']);
+    assert(ttCodon[(int)'X']!=nv);
     codonEncoder_.changeMode( &mode );
 
 
@@ -418,7 +418,7 @@
   seq->link( translatedSeq );
 
   // NB sequences are numbered 1...n not 0...n-1
-  for ( unsigned int i(1); i <= numSeqs ; i++ )
+  for ( int i(1); i <= numSeqs ; i++ )
   {
     //    cout << "hashing sequence " << i << endl;
     if( sequenceReader.getNextSequence( thisSeq, eDNAWordSizeForHashing) == -1 ) 
@@ -520,7 +520,7 @@
 int HashTableTranslated::getHitTypeSize( void ) const 
 {
   assert(1==0);
-  return NULL;
+  return 0;
 }
 void HashTableTranslated::allocateHitList( unsigned long size ) 
 {
