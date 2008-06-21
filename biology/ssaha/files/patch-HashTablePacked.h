--- ./HashTable/HashTablePacked.h.orig	2004-03-01 13:51:29.000000000 -0300
+++ ./HashTable/HashTablePacked.h	2008-06-12 15:39:31.000000000 -0300
@@ -236,11 +236,11 @@
     HashTableView<PositionPacked,HashTablePacked>
     (monitoringStream, name, hitListAllocator, arrayAllocator),
     wordNum_(0),
+    numRepeats_(0),
+    substituteThreshold_(0),
     pMatchSequence_(&HashTablePacked::matchSequenceStandard),
     pMatchWord_(&HashTablePacked::matchWordStandard),
     pGenerateSubstitutes_(&generateSubstitutesDNA),
-    numRepeats_(0),
-    substituteThreshold_(0),
     sorter_(4,(sizeof(PositionPacked)*8)/4)
     {
       hitListFormat_ = g32BitPacked;
