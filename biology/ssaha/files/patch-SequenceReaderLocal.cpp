--- ./SequenceReader/SequenceReaderLocal.cpp.orig	2004-03-01 13:51:30.000000000 -0300
+++ ./SequenceReader/SequenceReaderLocal.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -46,10 +46,10 @@
   // and seqNames_
 SequenceReaderLocal::SequenceReaderLocal
 ( SequenceReader& seqFile, int wordLength, ostream& monitoringStream ) :
-sourceData_( seqFile.getSourceDataType() ),
+SequenceReader( monitoringStream ),
 wordLength_( wordLength ),
 bitsPerSymbol_( seqFile.getBitsPerSymbol() ),
-SequenceReader( monitoringStream )
+sourceData_( seqFile.getSourceDataType() )
 {
   monitoringStream_ 
     << "constructing SequenceReaderLocal from SequenceReader" << endl;
@@ -72,10 +72,10 @@
 
 SequenceReaderLocal::SequenceReaderLocal
 ( int wordLength, int bitsPerSymbol, ostream& monitoringStream ) :
-sourceData_( gUnknownData ),
+SequenceReader( monitoringStream ),
 wordLength_( wordLength ),
 bitsPerSymbol_( bitsPerSymbol ),
-SequenceReader( monitoringStream )
+sourceData_( gUnknownData )
 {
   monitoringStream_ 
     << "constructing empty SequenceReaderLocal" << endl;
