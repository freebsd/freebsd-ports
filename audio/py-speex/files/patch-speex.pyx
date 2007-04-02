--- speex.pyx.orig	Sat Mar  3 00:32:39 2007
+++ speex.pyx	Sat Mar  3 00:33:01 2007
@@ -365,7 +365,7 @@
             bufOut[bufOutSiz] = nBytes % 256
             bufOut[bufOutSiz+1] = nBytes / 256
             bufOutSiz = bufOutSiz + 2
-            memcpy(bufOut+bufOutSiz, cbits, nBytes)
+            memcpy(bufOut+bufOutSiz, <void *> cbits, nBytes)
             # printf("ok5\n")
             bufOutSiz = bufOutSiz + nBytes
             # printf("ok6\n")
@@ -522,7 +522,7 @@
       
                     # Copy from float to short (16 bits) for output
                     for i from 0 <= i < self.encFramesPerBlock:
-                      decShorts1[i] = decFloats1[i]
+                      decShorts1[i] = <short> decFloats1[i]
       
                     self.decPhase = 0 #  back to awaiting LSB of count header
                     self.decNumBytes = 0
