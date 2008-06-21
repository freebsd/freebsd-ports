--- ./QueryManager/MatchStoreGapped.h.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./QueryManager/MatchStoreGapped.h	2008-06-12 15:39:31.000000000 -0300
@@ -57,7 +57,8 @@
 {
  public:
   MatchAlgorithm( int numRepeats ) : 
-    numRepeats_( numRepeats ), sortNeeded_(true) {}
+    sortNeeded_(true), numRepeats_( numRepeats )  {}
+  virtual ~MatchAlgorithm() {};
   void operator()  
     ( WordSequence& querySeq, 
       MatchAdder& addMatch, 
@@ -82,10 +83,10 @@
  public:
   MatchAlgorithmGapped
     ( int maxGap, int maxInsert, int minToProcess, int numRepeats ):
+    MatchAlgorithm( numRepeats ),
     maxGap_( maxGap ),
     maxInsert_( maxInsert ), 
-    minToProcess_( minToProcess ),
-    MatchAlgorithm( numRepeats )
+    minToProcess_( minToProcess )
     {}
 
   virtual void generateMatches
