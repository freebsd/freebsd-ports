--- IlmImf/ImfScanLineInputFile.cpp.orig	2018-08-10 01:34:58 UTC
+++ IlmImf/ImfScanLineInputFile.cpp
@@ -524,14 +524,14 @@ LineBufferTask::execute ()
     
         if (_lineBuffer->uncompressedData == 0)
         {
-            int uncompressedSize = 0;
+            size_t uncompressedSize = 0;
             int maxY = min (_lineBuffer->maxY, _ifd->maxY);
     
             for (int i = _lineBuffer->minY - _ifd->minY;
                  i <= maxY - _ifd->minY;
 		 ++i)
 	    {
-                uncompressedSize += (int) _ifd->bytesPerLine[i];
+                uncompressedSize += _ifd->bytesPerLine[i];
 	    }
     
             if (_lineBuffer->compressor &&
@@ -628,11 +628,11 @@ LineBufferTask::execute ()
                     //
     
                     char *linePtr  = slice.base +
-                                        divp (y, slice.ySampling) *
-                                        slice.yStride;
+                                        intptr_t( divp (y, slice.ySampling) ) *
+                                        intptr_t( slice.yStride );
     
-                    char *writePtr = linePtr + dMinX * slice.xStride;
-                    char *endPtr   = linePtr + dMaxX * slice.xStride;
+                    char *writePtr = linePtr + intptr_t( dMinX ) * intptr_t( slice.xStride );
+                    char *endPtr   = linePtr + intptr_t( dMaxX ) * intptr_t( slice.xStride );
                     
                     copyIntoFrameBuffer (readPtr, writePtr, endPtr,
                                          slice.xStride, slice.fill,
@@ -838,14 +838,14 @@ LineBufferTaskIIF::execute()
         
         if (_lineBuffer->uncompressedData == 0)
         {
-            int uncompressedSize = 0;
+            size_t uncompressedSize = 0;
             int maxY = min (_lineBuffer->maxY, _ifd->maxY);
             
             for (int i = _lineBuffer->minY - _ifd->minY;
             i <= maxY - _ifd->minY;
             ++i)
             {
-                uncompressedSize += (int) _ifd->bytesPerLine[i];
+                uncompressedSize += _ifd->bytesPerLine[i];
             }
             
             if (_lineBuffer->compressor &&
