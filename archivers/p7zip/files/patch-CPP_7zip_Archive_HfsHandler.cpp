Patch for CVE-2016-2334.

Obtained from: https://sourceforge.net/p/p7zip/discussion/383043/thread/9d0fb86b/
--- CPP/7zip/Archive/HfsHandler.cpp.orig	Fri Jun 19 06:52:08 2015
+++ CPP/7zip/Archive/HfsHandler.cpp	Mon May 23 20:37:42 2016
@@ -987,7 +987,9 @@ HRESULT CDatabase::LoadCatalog(const CFork &fork, cons
       item.GroupID = Get32(r + 0x24);
       item.AdminFlags = r[0x28];
       item.OwnerFlags = r[0x29];
+      */
       item.FileMode = Get16(r + 0x2A);
+      /*
       item.special.iNodeNum = Get16(r + 0x2C); // or .linkCount
       item.FileType = Get32(r + 0x30);
       item.FileCreator = Get32(r + 0x34);
@@ -1571,6 +1573,9 @@ HRESULT CHandler::ExtractZlibFile(
       blockSize = (UInt32)rem;
 
     UInt32 size = GetUi32(tableBuf + i * 8 + 4);
+
+    if (size > buf.Size() || size > kCompressionBlockSize + 1)
+        return S_FALSE;
 
     RINOK(ReadStream_FALSE(inStream, buf, size));
 
