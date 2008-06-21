--- ./SequenceReader/SequenceReaderFasta.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./SequenceReader/SequenceReaderFasta.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -135,9 +135,9 @@
     seqStopChar_( rhs.seqStopChar_ ),
     pInputFileStream_( new ifstream( rhs.fileName_.c_str() ) ),
     fileName_( rhs.fileName_.c_str() ),
-    seqPositions_( rhs.seqPositions_ ),
     //   lastSourceSeqNum_(0),
-    pEncoder_( rhs.pEncoder_->clone() )
+    pEncoder_( rhs.pEncoder_->clone() ),
+    seqPositions_( rhs.seqPositions_ )
   {
     monitoringStream_ << "copy constructing SequenceReaderFile" << this 
 		      << endl;
@@ -603,7 +603,7 @@
       throw SSAHAException
 	("Requested seq start exceeds requested seq end in SequenceReaderFile::extractSource");
   } // ~if
-  else if (seqEnd>lastSourceSeq_.size() )
+  else if (seqEnd>(SequenceOffset)lastSourceSeq_.size() )
   {
       throw SSAHAException
 	("Requested last byte exceeds end of seq in SequenceReaderFile::extractSource");
@@ -628,7 +628,7 @@
   computeNumSequencesInFile(); // ensure have scanned to end of file
   fileFile << fileName_ << endl;
   SeqIndexInfo* pIndex = new SeqIndexInfo[seqPositions_.size()];
-  for (int i(0) ; i < seqPositions_.size() ; i++)
+  for (unsigned int i(0) ; i < seqPositions_.size() ; i++)
   {
     pIndex[i].fileNum=fileNumber;
     pIndex[i].seqPos=seqPositions_[i];
