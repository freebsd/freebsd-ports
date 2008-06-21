--- ./QueryManager/MatchStore.h.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./QueryManager/MatchStore.h	2008-06-12 15:39:31.000000000 -0300
@@ -93,20 +93,20 @@
   virtual SequenceNumber getSubjectNum( void ) const 
     { return subjectNum_; }
   //  virtual inline string  getSubjectName( void ) const;
-  virtual inline const char*  getSubjectName( void ) const;
+  virtual const char*  getSubjectName( void ) const;
   virtual SequenceOffset getSubjectStart( void ) const 
     { return subjectStart_; }
   virtual SequenceOffset getSubjectEnd( void ) const 
     { return subjectEnd_; }
 
-  virtual inline SequenceNumber getQueryNum( void ) const;
-  virtual inline string         getQueryName( void ) const;
+  virtual SequenceNumber getQueryNum( void ) const;
+  virtual string         getQueryName( void ) const;
   virtual SequenceOffset getQueryStart( void ) const 
     { return queryStart_; }
   virtual SequenceOffset getQueryEnd( void ) const 
     { return queryEnd_; }
   
-  virtual inline int  getQuerySize( void ) const; 
+  virtual int  getQuerySize( void ) const; 
   virtual int  getNumBases(void ) const 
     { return numBases_; }
   virtual bool isQueryForward( void ) const 
@@ -127,7 +127,6 @@
              SequenceOffset subjectEnd,
              bool isQueryForward,
              bool isSubjectForward ):
-    myStore_( myStore ),
     subjectNum_( subjectNum ),  
     numBases_( numBases ),  
     queryStart_( queryStart ),
@@ -135,7 +134,8 @@
     subjectStart_( subjectStart ),
     subjectEnd_( subjectEnd ),
     isQueryForward_( isQueryForward ),
-    isSubjectForward_( isSubjectForward ){}
+    isSubjectForward_( isSubjectForward ),
+    myStore_( myStore )   {}
 
   SequenceNumber subjectNum_;
   SequenceOffset numBases_;
@@ -444,7 +444,7 @@
   ( 
     unsigned int maxToSort = 1<<30,
     double partialThreshold = 0.0
-  ) : sorter_(), maxToSort_(maxToSort), partialThreshold_(partialThreshold) {}
+  ) : maxToSort_(maxToSort), partialThreshold_(partialThreshold), sorter_()  {}
   // TBD should be virtual???
   void operator()(MatchStore& store )
   {
