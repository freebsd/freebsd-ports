--- ./SequenceReader/SequenceReaderMulti.h.orig	2004-03-01 13:51:30.000000000 -0300
+++ ./SequenceReader/SequenceReaderMulti.h	2008-06-12 15:39:31.000000000 -0300
@@ -81,8 +81,9 @@
     ( SequenceNumber lsn, 
       vector<SeqReaderInfo>::iterator tr,
       SequenceReaderState* ps ) :
+  SequenceReaderState(lsn),
   thisReader_(tr),  
-    pState_(ps), SequenceReaderState(lsn) {}
+  pState_(ps)  {}
   virtual ~SequenceReaderMultiState() {} //delete pState_;
   // no point in making this private as it's const
   const vector<SeqReaderInfo>::iterator thisReader_;
