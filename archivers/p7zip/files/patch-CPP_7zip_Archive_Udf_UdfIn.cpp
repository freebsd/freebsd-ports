Patch for CVE-2016-2335.

Obtained from: https://sourceforge.net/p/p7zip/discussion/383043/thread/9d0fb86b/
--- CPP/7zip/Archive/Udf/UdfIn.cpp.orig	Fri Nov 20 15:40:08 2015
+++ CPP/7zip/Archive/Udf/UdfIn.cpp	Mon May 23 20:37:46 2016
@@ -389,7 +389,11 @@ HRESULT CInArchive::ReadFileItem(int volIndex, int fsI
     return S_FALSE;
   CFile &file = Files.Back();
   const CLogVol &vol = LogVols[volIndex];
-  CPartition &partition = Partitions[vol.PartitionMaps[lad.Location.PartitionRef].PartitionIndex];
+  unsigned partitionRef = lad.Location.PartitionRef;
+
+  if (partitionRef >= vol.PartitionMaps.Size())
+  	return S_FALSE;
+  CPartition &partition = Partitions[vol.PartitionMaps[partitionRef].PartitionIndex];
 
   UInt32 key = lad.Location.Pos;
   UInt32 value;
