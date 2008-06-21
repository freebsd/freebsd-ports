--- ./SequenceReader/SequenceReaderString.h.orig	2004-03-01 13:51:30.000000000 -0300
+++ ./SequenceReader/SequenceReaderString.h	2008-06-12 15:39:31.000000000 -0300
@@ -65,9 +65,9 @@
   // NB SequenceReaderStringBase takes ownership of *pEncoder
   SequenceEncoder* pEncoder,
   ostream& monitoringStream = cerr ) :
+  SequenceReader( monitoringStream ),
   sequenceString_( sequenceString ), 
-  pEncoder_( pEncoder ),
-  SequenceReader( monitoringStream )
+  pEncoder_( pEncoder )
 {
   monitoringStream_ << "constructing SequenceReaderStringBase" << endl;
 } // constructor
@@ -78,9 +78,9 @@
   // TYPE  NAME  IN/OUT COMMENT
   // Returns: TYPE COMMENT
 SequenceReaderStringBase( const SequenceReaderStringBase& rhs ) :
+SequenceReader( rhs.monitoringStream_ ),
 sequenceString_( rhs.sequenceString_ ), 
-pEncoder_( rhs.pEncoder_->clone() ),
-SequenceReader( rhs.monitoringStream_ )
+pEncoder_( rhs.pEncoder_->clone() )
 {
   monitoringStream_ << "copy constructing SequenceReaderStringBase" << endl;
 } // copy constructor
