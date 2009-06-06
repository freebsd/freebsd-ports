--- fastaudio.pyx.orig	2004-06-15 20:37:39.000000000 +0900
+++ fastaudio.pyx	2009-06-06 18:54:52.000000000 +0900
@@ -92,7 +92,7 @@
 #@+node:portaudio.h
 # portaudio-specifics
 
-cdef extern from "../pa_common/portaudio.h":
+cdef extern from "%%LOCALBASE%%/include/portaudio.h":
     ctypedef int PaError
 
     cdef enum PA_ERRORS:
@@ -586,8 +586,8 @@
         cdata.framesPerBuf = framesPerBuf
         cdata.bytesPerFrame = channels * _sampleFormatSizes[format]
         cdata.bytesPerBuf = framesPerBuf * cdata.bytesPerFrame 
-        cdata.txFifo = fifoNew(cdata.bytesPerBuf, maxbufs, 't')
-        cdata.rxFifo = fifoNew(cdata.bytesPerBuf, maxbufs, 'r')
+        cdata.txFifo = fifoNew(cdata.bytesPerBuf, maxbufs, <int> 't')
+        cdata.rxFifo = fifoNew(cdata.bytesPerBuf, maxbufs, <int> 'r')
         printf("__new__: txFifo=%lx rxFifo=%lx\n", cdata.txFifo, cdata.rxFifo)
         cdata.hits = 0
         cdata.running = 1
@@ -1113,28 +1113,28 @@
             # write to output buffer, converting to output format
             if cChansOut == 1:
                 if outFormat == paInt8:
-                    outPtr_8[idxOut] = (frameLeft + frameRight) / (2 * 0x1000000)
+                    outPtr_8[idxOut] = <char> (frameLeft + frameRight) / (2 * 0x1000000)
                 elif outFormat == paUInt8:
-                    outPtr_u8[idxOut] = (frameLeft + frameRight) / (2 * 0x1000000)
+                    outPtr_u8[idxOut] = <unsigned char> (frameLeft + frameRight) / (2 * 0x1000000)
                 elif outFormat == paInt16:
-                    outPtr_16[idxOut] = (frameLeft + frameRight) / (2 * 0x10000)
+                    outPtr_16[idxOut] = <short> (frameLeft + frameRight) / (2 * 0x10000)
                 elif outFormat == paInt32:
-                    outPtr_32[idxOut] = (frameLeft + frameRight) / 2
+                    outPtr_32[idxOut] = <long> (frameLeft + frameRight) / 2
                 elif outFormat == paFloat32:
                     outPtr_f32[idxOut] = (frameLeft + frameRight) / 2
             else:
                 if outFormat == paInt8:
-                    outPtr_8[idxOut * 2] = frameLeft / 0x1000000
-                    outPtr_8[idxOut * 2 + 1] = frameRight / 0x1000000
+                    outPtr_8[idxOut * 2] = <char> frameLeft / 0x1000000
+                    outPtr_8[idxOut * 2 + 1] = <char> frameRight / 0x1000000
                 elif outFormat == paUInt8:
-                    outPtr_u8[idxOut * 2] = frameLeft / 0x1000000
-                    outPtr_u8[idxOut * 2 + 1] = frameRight / 0x1000000
+                    outPtr_u8[idxOut * 2] = <unsigned char> frameLeft / 0x1000000
+                    outPtr_u8[idxOut * 2 + 1] = <unsigned char> frameRight / 0x1000000
                 elif outFormat == paInt16:
-                    outPtr_16[idxOut * 2] = frameLeft / 0x10000
-                    outPtr_16[idxOut * 2 + 1] = frameRight / 0x10000
+                    outPtr_16[idxOut * 2] = <short> frameLeft / 0x10000
+                    outPtr_16[idxOut * 2 + 1] = <short> frameRight / 0x10000
                 elif outFormat == paInt32:
-                    outPtr_32[idxOut * 2] = frameLeft
-                    outPtr_32[idxOut * 2 + 1] = frameRight
+                    outPtr_32[idxOut * 2] = <long> frameLeft
+                    outPtr_32[idxOut * 2 + 1] = <long> frameRight
                 elif outFormat == paFloat32:
                     outPtr_f32[idxOut * 2] = frameLeft
                     outPtr_f32[idxOut * 2 + 1] = frameRight
