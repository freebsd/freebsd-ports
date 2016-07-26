--- XADMaster/XADWinZipWavPackHandle.h.orig	2016-05-17 06:39:04 UTC
+++ XADMaster/XADWinZipWavPackHandle.h
@@ -1,6 +1,6 @@
 #import "CSBlockStreamHandle.h"
 
-#import "wavpack/wavpack.h"
+#import <wavpack/wavpack.h>
 
 @interface XADWinZipWavPackHandle:CSBlockStreamHandle
 {
