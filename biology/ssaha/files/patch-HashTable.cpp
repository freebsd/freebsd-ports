--- ./HashTable/HashTable.cpp.orig	2004-03-01 13:51:28.000000000 -0300
+++ ./HashTable/HashTable.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -265,7 +265,7 @@
 void HashTable::countWords( SequenceAdapter& thisSeq )
 {
 
-   for ( int j(0) ; j < thisSeq.size() ; ++ j )
+   for ( WordSequence::size_type j(0) ; j < thisSeq.size() ; ++ j )
    {
      // only count words that have not been flagged
      pWordPositionInHitList_[(thisSeq[j]&(~gCursedWord))]
@@ -284,7 +284,7 @@
       // NB We stop at the last but one element of the 
       // sequence (as the last isn't a full word)
 
-   for ( int j(0) ; j < thisSeq.size() ; ++ j )
+   for ( WordSequence::size_type j(0) ; j < thisSeq.size() ; ++ j )
       {
 	thisWord = thisSeq[j];
 	// only hash words that have not been flagged
