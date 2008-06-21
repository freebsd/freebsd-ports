--- ./HashTable/testHashTableNoOverlap.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./HashTable/testHashTableNoOverlap.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -70,10 +70,10 @@
   cout << "     Test of class HashTable" << endl << endl;
   cout << "*******************************************" << endl << endl;
 
-  int numSeqs = 10;
-  int seqSize = 100;
-  int wordLength = 10;
-  int maxHits = 50;
+  unsigned int numSeqs = 10;
+  unsigned int seqSize = 100;
+  unsigned int wordLength = 10;
+  unsigned int maxHits = 50;
 
   // Generate a random sequence of (numSeqs*seqSize) base pairs ...
   // 1128 is the seed value for the random number generator
@@ -116,7 +116,7 @@
   // so we are checking that all sequence data 'finds itself' in the hash
   // table in the correct position
 
-  for ( int i(1) ; i <= numSeqs ; i++ )
+  for ( unsigned int i(1) ; i <= numSeqs ; i++ )
   { // for each sequence in testReader ...
     testReader.getNextSequence(seq,wordLength);
 
@@ -131,7 +131,7 @@
     cout << seq.getNumBasesInLast() << "!!\n";
     // ... go through the Words in the sequence one by one and look
     //    for matches in the hash table
-    for ( int j(0) ; j < (seqSize/wordLength) ; j++ )
+    for ( unsigned int j(0) ; j < (seqSize/wordLength) ; j++ )
     {
        cout << j << " " << printBase(seq[j],wordLength) << endl; 
       
@@ -146,7 +146,7 @@
        // ... and that the sequence number and offset for the hit are OK
 
        assert(hits[0].subjectNum == i );
-       assert(hits[0].diff == j*wordLength );
+       assert((unsigned int)hits[0].diff == j*wordLength );
        assert(hits[0].queryPos == 1);
  
        hits.clear();
@@ -157,12 +157,12 @@
     testHash.matchWord(seq,hits); 
     cout << hits.size() << "!!!!!\n";
     assert( hits.size() == (seqSize/wordLength) );
-    for ( int j(0) ; j < hits.size() ; j ++ )
+    for ( unsigned int j(0) ; j < hits.size() ; j ++ )
     {
 
       assert(hits[j].subjectNum == i);
       assert(hits[j].diff   == 0);
-      assert(hits[j].queryPos == 1 + ( j * wordLength ) );
+      assert((unsigned int)hits[j].queryPos == 1 + ( j * wordLength ) );
      
     } // ~for j
 
@@ -194,7 +194,7 @@
   assert( testLoad.isInitialized() == true );
   
   // and that word length matches original
-  assert( testLoad.getWordLength() == wordLength );
+  assert( (unsigned int)testLoad.getWordLength() == wordLength );
 
   testLoad.setMaxNumHits( testHash.getMaxNumHits() );
 
@@ -208,7 +208,7 @@
   // and new hash tables, storing the resulting hits in hitsOrig and
   // hitsCopy respectively.
 
-  for ( int i(0) ; i < numSeqs ; i++ )
+  for ( unsigned int i(0) ; i < numSeqs ; i++ )
   {
 
     // ... check that the name strings match 
@@ -258,7 +258,7 @@
   HashTable   shiftHash(cout);
   creator.createHashTable(shiftHash,shiftReader,wordLength,maxHits);
 
-  for ( int i(0) ; i < wordLength ; i++ )
+  for ( unsigned int i(0) ; i < wordLength ; i++ )
   {
     testSeq = testSeq.substr(1); // delete first character
     { // braces ensure a new instance is created each time round loop
@@ -460,7 +460,7 @@
     SequenceEncoderCodon encoder;
     encoder.setWordLength(wordLength);
 
-    for ( int i(1) ; i < hashTrans.getNumSequences() ; i++ )
+    for ( unsigned int i(1) ; i < hashTrans.getNumSequences() ; i++ )
     {
 
       hashTrans.getSequenceName( s1, i );
@@ -477,7 +477,7 @@
       assert(hashTrans.getSequenceSize(i)==hashTrans2.getSequenceSize(i));
 
       assert( (((w1.size()-1) * gMaxBasesPerWord ) + w1.getNumBasesInLast())
-	      == hashTrans.getSequenceSize(i));
+	      == (unsigned int)hashTrans.getSequenceSize(i));
 
 
       // Sequence should produce same (nonzero) num hits in fwd direction
@@ -573,19 +573,19 @@
     string s, s1;
     Word w;
     vector<Word> subs;
-    int wl=15;
+    unsigned int wl=15;
 
     // test substitution for DNA
     // 
 
-    for (int i(0); i<wl; i++) s+="A";
+    for ( unsigned int i(0); i<wl; i++) s+="A";
 
     w = makeBase(s);
 
     generateSubstitutesDNA( w, subs, wl );
     assert(subs.size()==wl);
     
-    for (int i(0); i<wl ; i++)
+    for (unsigned int i(0); i<wl ; i++)
     {
       cout << printWord(subs[i],wl) << endl;
       s1=s;
@@ -596,14 +596,14 @@
     //
     s=""; subs.clear();
 
-    for (int i(0); i<wl; i++) s+="C";
+    for (unsigned int i(0); i<wl; i++) s+="C";
 
     w = makeBase(s);
 
     generateSubstitutesDNA( w, subs, wl );
     assert(subs.size()==wl);
     
-    for (int i(0); i<wl ; i++)
+    for (unsigned int i(0); i<wl ; i++)
     {
       cout << printWord(subs[i],wl) << endl;
       s1=s;
@@ -614,14 +614,14 @@
     //
     s=""; subs.clear();
 
-    for (int i(0); i<wl; i++) s+="G";
+    for (unsigned int i(0); i<wl; i++) s+="G";
 
     w = makeBase(s);
 
     generateSubstitutesDNA( w, subs, wl );
     assert(subs.size()==wl);
     
-    for (int i(0); i<wl ; i++)
+    for (unsigned int i(0); i<wl ; i++)
     {
       cout << printWord(subs[i],wl) << endl;
       s1=s;
@@ -632,14 +632,14 @@
     //
     s=""; subs.clear();
 
-    for (int i(0); i<wl; i++) s+="T";
+    for (unsigned int i(0); i<wl; i++) s+="T";
 
     w = makeBase(s);
 
     generateSubstitutesDNA( w, subs, wl );
     assert(subs.size()==wl);
     
-    for (int i(0); i<wl ; i++)
+    for (unsigned int i(0); i<wl ; i++)
     {
       cout << printWord(subs[i],wl) << endl;
       s1=s;
