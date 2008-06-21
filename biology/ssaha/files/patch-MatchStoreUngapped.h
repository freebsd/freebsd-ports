--- ./QueryManager/MatchStoreUngapped.h.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./QueryManager/MatchStoreUngapped.h	2008-06-12 15:39:31.000000000 -0300
@@ -60,8 +60,8 @@
  public:
   MatchAlgorithmUngapped
     ( int minToProcess, int numRepeats ):
-    minToProcess_( minToProcess ),
-    MatchAlgorithm( numRepeats )
+    MatchAlgorithm( numRepeats ),
+    minToProcess_( minToProcess )
     {}
 
   virtual void generateMatches
