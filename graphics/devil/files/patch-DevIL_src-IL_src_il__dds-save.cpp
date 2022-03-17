--- DevIL/src-IL/src/il_dds-save.cpp.orig	2017-01-01 23:37:37 UTC
+++ DevIL/src-IL/src/il_dds-save.cpp
@@ -708,7 +708,7 @@ ILuint Compress(ILimage *Image, ILenum DXTCFormat)
 			if (DXTCFormat == IL_DXT1 || DXTCFormat == IL_DXT1A || DXTCFormat == IL_DXT3 || DXTCFormat == IL_DXT5) {
 				// NVTT needs data as BGRA 32-bit.
 				if (Image->Format != IL_BGRA || Image->Type != IL_UNSIGNED_BYTE) {  // No need to convert if already this format/type.
-					ByteData = ilConvertBuffer(Image->SizeOfData, Image->Format, IL_BGRA, Image->Type, IL_UNSIGNED_BYTE, NULL, Image->Data);
+					ByteData = (ILubyte*)ilConvertBuffer(Image->SizeOfData, Image->Format, IL_BGRA, Image->Type, IL_UNSIGNED_BYTE, NULL, Image->Data);
 					if (ByteData == NULL)
 						return 0;
 				}
