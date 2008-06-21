--- ./SequenceReader/SequenceReader.cpp.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./SequenceReader/SequenceReader.cpp	2008-06-12 15:39:31.000000000 -0300
@@ -179,7 +179,7 @@
 
   for ( ; i != reverseBuffer_.end() ; i++, j-- )
   {
-    *i= reverseChar[ *j ];
+    *i= reverseChar[ (int) *j ];
     //    cout << "char: " << (int)*j << *j << " - " << (int)*i << *i << endl;
   }
 
@@ -356,7 +356,7 @@
       throw SSAHAException
 	("Requested seq start exceeds requested seq end in SourceReaderIndex::extractSource");
   } // ~if
-  else if (seqEnd>lastSourceSeq_.size() )
+  else if (seqEnd>(int)lastSourceSeq_.size() )
   {
     cout << seqEnd << " " << lastSourceSeq_.size() << endl;
       throw SSAHAException
