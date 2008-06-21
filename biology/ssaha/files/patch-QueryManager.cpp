--- ./QueryManager/QueryManager.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./QueryManager/QueryManager.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -164,8 +164,8 @@
 // MatchPolicy member function definitions
 
 MatchPolicy::MatchPolicy( HashTableGeneric& subjectTable ) :
-  subjectTable_( subjectTable ), 
-  queryWordLength_( subjectTable.getWordLength() ) 
+  queryWordLength_( subjectTable.getWordLength() ),
+  subjectTable_( subjectTable )
 {}
 
 
@@ -203,8 +203,8 @@
 
 MatchPolicyProteinProtein::MatchPolicyProteinProtein
 ( HashTablePackedProtein& subjectTable ) :
-subjectTable_( subjectTable ),
-MatchPolicy( subjectTable )
+MatchPolicy( subjectTable ),
+subjectTable_( subjectTable )
 {
 
   subjectTable_.setQueryProtein();
@@ -386,9 +386,9 @@
   QueryManager::QueryManager
   ( SequenceReader& querySeqs,  
     HashTableGeneric& subjectSeqs, ostream& monitoringStream ) :
-   queryReader_( querySeqs ), 
    subjectTable_(  subjectSeqs ), 
-   monitoringStream_( monitoringStream )
+   monitoringStream_( monitoringStream ),
+   queryReader_( querySeqs ) 
    {
      monitoringStream_ << "constructing QueryManager\n";
 
@@ -518,7 +518,7 @@
 
       task( store );
 
-      if ( queryReader_.getLastSequenceNumber() == queryEnd ) break;
+      if ( (int)queryReader_.getLastSequenceNumber() == queryEnd ) break;
 
       // clear the query sequence ready to read in next query
       querySeqFwd.clear();
@@ -530,7 +530,7 @@
     } // ~while
     while ( numBasesInLast != -1 );
 
-    if (    ( queryReader_.getLastSequenceNumber() < queryEnd  )
+    if (    ( (int)queryReader_.getLastSequenceNumber() < queryEnd  )
          && ( queryEnd != - 1 ) )
     {
       monitoringStream_ << "Info: requested final sequence (" << queryEnd
