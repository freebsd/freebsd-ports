--- Emulator/ROM/TROMImage.cpp.orig	2025-12-19 16:57:53 UTC
+++ Emulator/ROM/TROMImage.cpp
@@ -100,7 +100,7 @@ TROMImage::CreateImage(const KUInt8* inBuffer)
 		++dest;
 	} while (++src < end);
 #else
-	(void) ::memcpy(theImagePtr, inBuffer, inBufferSize);
+	(void) ::memcpy(theImagePtr, inBuffer, TMemoryConsts::kROMEnd);
 #endif
 
 	mROMId = ComputeROMId(theImagePtr->fROM, mCRCValid);
