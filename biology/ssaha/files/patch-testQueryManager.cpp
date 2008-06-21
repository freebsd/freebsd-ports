--- ./QueryManager/testQueryManager.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./QueryManager/testQueryManager.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -53,7 +53,7 @@
 void reverseString( string& seq )
 {
   string rc;
-  for ( int i(0) ; i < seq.size() ; i++ )
+  for ( unsigned int i(0) ; i < seq.size() ; i++ )
   {
     if  ( ( seq[i] == 'A' ) || (seq[i] == 'a') ) rc = 'T' + rc; 
     else if ( ( seq[i] == 'T' ) || (seq[i] == 't') ) rc = 'A' + rc; 
@@ -165,7 +165,7 @@
   int numSeqs = 3;
   int seqSize = 1000;
   int wordLength = 7;
-  int maxHits = 50;
+//  int maxHits = 50;
 
   // Generate a random sequence of (numSeqs*seqSize) base pairs ...
   // 1128 is the seed value for the random number generator
