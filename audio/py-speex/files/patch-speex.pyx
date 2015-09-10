--- speex.pyx.orig	2003-11-24 05:29:33 UTC
+++ speex.pyx
@@ -365,7 +365,7 @@ cdef class new:
             bufOut[bufOutSiz] = nBytes % 256
             bufOut[bufOutSiz+1] = nBytes / 256
             bufOutSiz = bufOutSiz + 2
-            memcpy(bufOut+bufOutSiz, cbits, nBytes)
+            memcpy(bufOut+bufOutSiz, <void *> cbits, nBytes)
             # printf("ok5\n")
             bufOutSiz = bufOutSiz + nBytes
             # printf("ok6\n")
@@ -522,7 +522,7 @@ cdef class new:
       
                     # Copy from float to short (16 bits) for output
                     for i from 0 <= i < self.encFramesPerBlock:
-                      decShorts1[i] = decFloats1[i]
+                      decShorts1[i] = <short> decFloats1[i]
       
                     self.decPhase = 0 #  back to awaiting LSB of count header
                     self.decNumBytes = 0
