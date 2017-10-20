Description: Fix typos and remove some warnings
Author: Mathieu Malaterre <malat@debian.org>

Cleaned up for FreeBSD by mi

--- jxrencoderdecoder/JxrEncApp.c.orig	2017-10-20 15:09:28 UTC
+++ jxrencoderdecoder/JxrEncApp.c
@@ -578,7 +578,7 @@ main(int argc, char* argv[])
 
     //================================
     Call(PKCreateCodecFactory(&pCodecFactory, WMP_SDK_VERSION));
-    Call(pCodecFactory->CreateCodec(&IID_PKImageWmpEncode, &pEncoder));
+    Call(pCodecFactory->CreateCodec(&IID_PKImageWmpEncode, (void**)&pEncoder));
 
     //----------------------------------------------------------------
     Call(PKCreateTestFactory(&pTestFactory, WMP_SDK_VERSION));
