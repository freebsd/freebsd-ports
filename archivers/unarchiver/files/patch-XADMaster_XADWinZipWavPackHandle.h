--- XADMaster/XADWinZipWavPackHandle.h.orig	2015-09-23 20:24:59 UTC
+++ XADMaster/XADWinZipWavPackHandle.h
@@ -1,6 +1,6 @@
 #import "CSBlockStreamHandle.h"
 
-#import "wavpack/wavpack.h"
+#import <wavpack/wavpack.h>
 
 @interface XADWinZipWavPackHandle:CSBlockStreamHandle
 {
