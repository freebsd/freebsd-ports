--- ./SequenceReader/SequenceEncoder.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./SequenceReader/SequenceEncoder.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -54,10 +54,10 @@
     ostream& monitoringStream):
     monitoringStream_( monitoringStream ),
     tt_(tt), sourceData_( sourceData ), bitsPerSymbol_(bitsPerSymbol),
+    symbolMask_((1<<bitsPerSymbol)-1),
     pState_( new SequenceReaderModeIgnore( monitoringStream ) ),
     wordFlag_(0),
-    doubleBitShift_(bitsPerSymbol<<1),
-    symbolMask_((1<<bitsPerSymbol)-1)
+    doubleBitShift_(bitsPerSymbol<<1)
   //    numSymbolPairs_(wordLength>>1),
   //   oddNumSymbols_(wordLength%1==1),
   { 
@@ -71,13 +71,13 @@
   ett_( rhs.ett_ ),
   sourceData_( rhs.sourceData_ ),
   bitsPerSymbol_( rhs.bitsPerSymbol_ ),
+  symbolMask_(rhs.symbolMask_),
   wordLength_( rhs.wordLength_ ),
     //  pSeq_( rhs.pSeq_ ),// don't want 2 encoders linking to same seq
   pState_( rhs.pState_->clone() ),
   wordFlag_(0),
   //  numSymbolPairs_(rhs.numSymbolPairs_),
   //  oddNumSymbols_(rhs.oddNumSymbols_),
-  symbolMask_(rhs.symbolMask_),
   doubleBitShift_(rhs.doubleBitShift_)
   {
     monitoringStream_ << "copy constructing SequenceEncoder" << endl;
@@ -218,7 +218,7 @@
   {
     pTemp = (uchar*)p;
     //    cout << basesInLast << " doing odd char at end " << *pTemp << endl;
-    encodeChar( *p, thisWord, wordFlag_, basesInLast );
+    encodeChar( *pTemp, thisWord, wordFlag_, basesInLast );
   }
 
   pSeq_->setNumBasesInLast(basesInLast);
@@ -453,7 +453,7 @@
 
     for( ; i!=lastWord ; ++i )
     {
-      if (toCarry!=~0)
+      if (toCarry!=(Word)~0)
       (*pCodon++) = ( ((*i)&gCursedWord)|lastWordFlag )
 	? flaggedChar
 	: ( toCarry | (((*i) >> (4*gCodonBits + 2*gBaseBits))&maskBase ));
@@ -488,7 +488,7 @@
 
     for( ; i!=lastWord ; ++i )
     {
-      if (toCarry!=~0)
+      if (toCarry!=(Word)~0)
       (*pCodon++) = ( ((*i)&gCursedWord)|lastWordFlag )
 	? flaggedChar
 	: ( toCarry | (((*i) >> (4*gCodonBits + gBaseBits))&mask2Bases ));
@@ -610,7 +610,7 @@
     do
     {
       i--;
-      if (toCarry!=~0)
+      if (toCarry!=(Word)~0)
       (*pCodon++) = ( ((*i)&gCursedWord)|lastWordFlag )
 	? flaggedChar
 	: ( toCarry | ( ((*i) & mask2Bases ) << gBaseBits ) );
@@ -650,7 +650,7 @@
     do
     {
       i--;
-      if (toCarry!=~0)
+      if (toCarry!=(Word)~0)
       (*pCodon++) = ( ((*i)&gCursedWord)|lastWordFlag )
 	? flaggedChar
 	: ( toCarry | ( ((*i) & maskBase ) << (2*gBaseBits) ) );
