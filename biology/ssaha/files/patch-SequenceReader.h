--- ./SequenceReader/SequenceReader.h.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./SequenceReader/SequenceReader.h	2008-06-12 15:39:31.000000000 -0300
@@ -264,6 +264,8 @@
     pReader_( rhs.pReader_ ),
     seqNum_( rhs.seqNum_ ) {}
 
+    // A virtual destructor is required because this is a base class.
+    virtual ~SequenceReaderPrinter() {};
 
     SequenceReaderPrinter& operator()( SequenceNumber inSeqNum )
     { 
