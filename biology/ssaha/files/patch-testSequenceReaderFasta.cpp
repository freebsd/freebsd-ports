--- ./SequenceReader/testSequenceReaderFasta.cpp.orig	2004-08-25 11:31:17.000000000 -0300
+++ ./SequenceReader/testSequenceReaderFasta.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -49,12 +49,12 @@
 // ### Function Definitions ###
 void capitalise( string& s )
 {
-  for ( int i(0) ; i < s.size() ; ++i ) s[i] = toupper(s[i]);
+  for ( unsigned int i(0) ; i < s.size() ; ++i ) s[i] = toupper(s[i]);
 }
 void reverseString( string& seq )
 {
   string rc;
-  for ( int i(0) ; i < seq.size() ; i++ )
+  for ( unsigned int i(0) ; i < seq.size() ; i++ )
   {
     if  ( ( seq[i] == 'A' ) || (seq[i] == 'a') ) rc = 'T' + rc; 
     else if ( ( seq[i] == 'T' ) || (seq[i] == 't') ) rc = 'A' + rc; 
@@ -91,7 +91,7 @@
   cout << "Test " << ++numTests <<": test of function getNextSequence" 
        << endl << endl;
 
-  int numSeqs = 10;
+  unsigned int numSeqs = 10;
   int seqSize = 57;
 
   // Generate a random sequence of (numSeqs*seqSize) base pairs ...
@@ -118,7 +118,7 @@
 
 
 
-  for ( int i(0) ; i < numSeqs ; i++ )
+  for ( unsigned int i(0) ; i < numSeqs ; i++ )
   {
   
     testReader.getNextSequence(w,wordLength);
@@ -188,7 +188,7 @@
   cout << "Test " << ++numTests <<": test of getSequence" 
        << endl << endl;
 
-    int toRead = 5;
+    unsigned int toRead = 5;
 
     w.clear();
     testReader.getSequence(w,toRead,wordLength);
@@ -242,7 +242,7 @@
     cout << "Test " << ++numTests <<": test of random access output functions" 
        << endl << endl;
 
-    for ( int i(1) ; i <= numSeqs; i++ )
+    for ( unsigned int i(1) ; i <= numSeqs; i++ )
     {
       cout << testReader.getName(i) << endl;
       cout << testReader.getSideInfo(i) << endl;
@@ -275,7 +275,7 @@
   // add on the end of the expected sequence string for it to match actual.
   //  const string spareBases( wordLength - ( seqSize % wordLength ), 'A');
 
-  for ( int i(0) ; i < numSeqs ; i++ )
+  for ( unsigned int i(0) ; i < numSeqs ; i++ )
   {
   
     testReaderFastq.getNextSequence(w,wordLength);
@@ -403,7 +403,7 @@
     cout << "Test " << ++numTests <<": test of random access output functions" 
        << endl << endl;
 
-    for ( int i(1) ; i <= numSeqs; i++ )
+    for ( unsigned int i(1) ; i <= numSeqs; i++ )
     {
       cout << testReaderFastq.getName(i) << endl;
       cout << testReaderFastq.getSideInfo(i) << endl;
@@ -466,7 +466,7 @@
     {
 
       testReader.rewind();
-      for ( int j(0) ; j < testReader.getNumSequencesInFile() ; j ++ ) 
+      for ( unsigned int j(0) ; j < testReader.getNumSequencesInFile() ; j ++ ) 
       {
 		cout << i << " " << j << endl;
         wSingle.clear(); wMulti.clear(); 
@@ -772,7 +772,7 @@
       
       for (int wordLength(9); wordLength <= 12; wordLength++)
       {
-	for (int i(0) ; i < fiftyAs.size(); i++)
+	for (unsigned int i(0) ; i < fiftyAs.size(); i++)
 	{
 	  thisString=fiftyAs;
 	  thisString[i]='X';
@@ -793,7 +793,7 @@
 	  stringReader.changeMode(&ignore);
 	  w.clear();
 	  numInLast = stringReader.getNextSequence(w,wordLength);
-	  assert(numInLast==(fiftyAs.size()-1)%wordLength);
+	  assert(numInLast==(int)(fiftyAs.size()-1)%wordLength);
 	  assert((w.size()-1)*wordLength+numInLast==fiftyAs.size()-1);
 
 	  for (WordSequence::iterator j(w.begin()); j!=w.end();j++)
@@ -810,7 +810,7 @@
 	  numInLast = stringReader.getNextSequence(w,wordLength);
 	  cout << "blegh " << wordLength << " " << i  << " " << fiftyAs.size() << " " << numInLast << " " << w.size() << endl;
 	  
-	  assert(numInLast==fiftyAs.size()%wordLength);
+	  assert(numInLast==(int)fiftyAs.size()%wordLength);
 	  assert((w.size()-1)*wordLength+numInLast==fiftyAs.size());
 
 	  for (WordSequence::iterator j(w.begin()); j!=w.end();j++)
@@ -828,7 +828,7 @@
 	  stringReader.changeMode(&tag);
 	  w.clear();
 	  numInLast = stringReader.getNextSequence(w,wordLength);
-	  assert(numInLast==fiftyAs.size()%wordLength);
+	  assert(numInLast==(int)fiftyAs.size()%wordLength);
 	  assert((w.size()-1)*wordLength+numInLast==fiftyAs.size());
 
 	  for (WordSequence::iterator j(w.begin()); j!=w.end();j++)
@@ -915,7 +915,7 @@
       cout << "actual:   " << printResidue(W,wordLength) << endl;
       
 
-      for ( int i(0),j(0);  i < protString.size() ; i+=wordLength,j++ )
+      for ( unsigned int i(0),j(0);  i < protString.size() ; i+=wordLength,j++ )
 	{
 	  wordString = protString.substr(i, wordLength);
 	  cout << wordString << " " << printResidue(W[j],wordLength) << endl;
@@ -1163,7 +1163,7 @@
           assert (    localReader.getNumSequencesInFile()
                ==  testReader.getNumSequencesInFile() );
 
-            for ( int j(0) ; j < testReader.getNumSequencesInFile() ; j ++ ) 
+            for ( unsigned int j(0) ; j < testReader.getNumSequencesInFile() ; j ++ ) 
         {
           wSingle.clear(); wMulti.clear(); 
 
@@ -1244,7 +1244,7 @@
      WordSequence seq;
      string name;
 
-     for ( int i(1) ; i <= filterer.getNumSequencesInFile() ; i++ )
+     for ( unsigned int i(1) ; i <= filterer.getNumSequencesInFile() ; i++ )
      {
        filterer.getSequence(seq, i, 16);
        filterer.getLastSequenceName(name);
@@ -1330,12 +1330,12 @@
        //       assert(v1==v1i);
        //     assert(v2==v2i);
 
-       for ( int (i(j)) ; i <=seqSize ; i++ ) assert(v1[i-j]==data[i-1]);
-       for ( int (i(j)) ; i <=seqSize ; i++ ) assert(v2[i-j]==data[i-1]);
-       for ( int (i(j)) ; i <=seqSize ; i++ ) assert(v1m[i-j]==data[i-1]);
-       for ( int (i(j)) ; i <=seqSize ; i++ ) assert(v2m[i-j]==data[i-1]);
-       for ( int (i(j)) ; i <=seqSize ; i++ ) assert(v1i[i-j]==data[i-1]);
-       for ( int (i(j)) ; i <=seqSize ; i++ ) assert(v2i[i-j]==data[i-1]);
+       for ( int i(j) ; i <=seqSize ; i++ ) assert(v1[i-j]==data[i-1]);
+       for ( int i(j) ; i <=seqSize ; i++ ) assert(v2[i-j]==data[i-1]);
+       for ( int i(j) ; i <=seqSize ; i++ ) assert(v1m[i-j]==data[i-1]);
+       for ( int i(j) ; i <=seqSize ; i++ ) assert(v2m[i-j]==data[i-1]);
+       for ( int i(j) ; i <=seqSize ; i++ ) assert(v1i[i-j]==data[i-1]);
+       for ( int i(j) ; i <=seqSize ; i++ ) assert(v2i[i-j]==data[i-1]);
 
      }
      cout << "got through  first bit" << endl;
@@ -1402,7 +1402,7 @@
 
      string n1,n2;
 
-     for (int i(0);i<numSeqs; i++)
+     for (unsigned int i(0);i<(unsigned int)numSeqs; i++)
      {
        cout << "i: " << i << endl;
        w1.clear(); w2.clear();
