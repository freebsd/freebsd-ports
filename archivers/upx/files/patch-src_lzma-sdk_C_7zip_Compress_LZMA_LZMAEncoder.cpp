--- src/lzma-sdk/C/7zip/Compress/LZMA/LZMAEncoder.cpp.orig	2016-11-20 12:55:06 UTC
+++ src/lzma-sdk/C/7zip/Compress/LZMA/LZMAEncoder.cpp
@@ -968,7 +968,7 @@ HRESULT CEncoder::GetOptimum(UInt32 position, UInt32 &
         startLen = lenTest + 1;
 
       // if (_maxMode)
-        {
+      {
           UInt32 lenTest2 = lenTest + 1;
           UInt32 limit = MyMin(numAvailableBytesFull, lenTest2 + _numFastBytes);
           for (; lenTest2 < limit &&
