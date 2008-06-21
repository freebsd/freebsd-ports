--- ./QueryManager/QueryManager.h.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./QueryManager/QueryManager.h	2008-06-12 15:39:31.000000000 -0300
@@ -145,6 +145,7 @@
     //    readFrame_(0), 
     pStore_(NULL), 
     subjectTable_( subjectTable ) {}
+  virtual ~MatchAdder() {};
   virtual void operator()(  SequenceNumber subjectNum,
 			    SequenceOffset numBases,
 			    SequenceOffset queryStart,
@@ -172,7 +173,7 @@
 {
 public:
   MatchAdderImp( HashTableGeneric& subjectTable ) : 
-    lastSubjectNum_(0), name_(), MatchAdder( subjectTable ) {}
+    MatchAdder( subjectTable ), name_(), lastSubjectNum_(0)  {}
     virtual void operator()(  SequenceNumber subjectNum,
 				     SequenceOffset numBases,
 				     SequenceOffset queryStart,
