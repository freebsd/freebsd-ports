--- ./SequenceReader/SequenceReaderFasta.h.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./SequenceReader/SequenceReaderFasta.h	2008-06-12 15:39:31.000000000 -0300
@@ -55,7 +55,7 @@
 {
  public:
   SequenceReaderFileState( SequenceNumber lsn, std::streampos fp ) :
-  filePos_(fp),  SequenceReaderState(lsn) {}
+  SequenceReaderState(lsn), filePos_(fp)  {}
   // no point in making this private as it's const
   const std::streampos filePos_;
 };
