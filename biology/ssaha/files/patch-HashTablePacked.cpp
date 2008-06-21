--- ./HashTable/HashTablePacked.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./HashTable/HashTablePacked.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -132,7 +132,7 @@
 void HashTablePacked::countWords( SequenceAdapter& thisSeq )
 {
 
-   for ( int j(0) ; j < thisSeq.size() ; ++ j )
+   for ( WordSequence::size_type j(0) ; j < thisSeq.size() ; ++ j )
    {
      // only count words that have not been flagged
      pWordPositionInHitList_[(thisSeq[j]&(~gCursedWord))]
@@ -151,7 +151,7 @@
   // NB We stop at the last but one element of the 
   // sequence (as the last isn't a full word)
 
-   for ( int j(0) ; j < thisSeq.size() ; ++ j )
+   for ( WordSequence::size_type j(0) ; j < thisSeq.size() ; ++ j )
       {
 	thisWord = thisSeq[j];
 
@@ -200,7 +200,7 @@
       for ( WordSequence::const_iterator thisWord(seq.begin());
             thisWord != last ; ++thisWord )
       {
-	int oldSize(packedHits.size()); // %%%%%%
+//	int oldSize(packedHits.size()); // %%%%%%
 	matchWordDeluxe( *thisWord, packedHits, baseOffset );
 	//	cout << printResidue(*thisWord, wordLength_) << " "
 	//  << packedHits.size()-oldSize;
