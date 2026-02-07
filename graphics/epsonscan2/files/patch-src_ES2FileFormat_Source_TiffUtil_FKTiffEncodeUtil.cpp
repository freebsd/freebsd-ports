--- src/ES2FileFormat/Source/TiffUtil/FKTiffEncodeUtil.cpp.orig	2024-09-12 07:10:33 UTC
+++ src/ES2FileFormat/Source/TiffUtil/FKTiffEncodeUtil.cpp
@@ -192,8 +192,8 @@ BAIL:;
 BAIL:;
  return errorCode == kFKNoError;
 }
-BOOL FKTiffEncodeUtil::StartWithPath(ESString& path, ESImageInfo& imageInfo, uint32 compression,
-          BOOL appendMode, ESString& iccProfilePath, ENUM_FK_ERROR_CODE& eError,uint32 un32JpegQuality)
+BOOL FKTiffEncodeUtil::StartWithPath(ESString& path, ESImageInfo& imageInfo, uint32_t compression,
+          BOOL appendMode, ESString& iccProfilePath, ENUM_FK_ERROR_CODE& eError,uint32_t un32JpegQuality)
 {
  eError = kFKNoError;
  if (m_bStarted || !OpenOutFileWithPath(&path, appendMode)){
@@ -210,7 +210,7 @@ BOOL FKTiffEncodeUtil::StartWithPath(ESString& path, E
   m_nSamplesPerPixel = samplesPerPixel;
   m_nBytesPerLine = ES_IMAGE_INFO::GetESImageBytesPerRow(imageInfo);
   m_nCompressionType = compression;
-  uint32 colorSpace = GetTiffColorSpace(samplesPerPixel, compression);
+  uint32_t colorSpace = GetTiffColorSpace(samplesPerPixel, compression);
   if (TIFFSetField(m_pOutFile, TIFFTAG_IMAGEWIDTH, imageWidth) != 1) {
    ES_ErrorBailWithAction(FALSE, BAIL, this, eError = kFKTiffSetFieldError, ES_STRING("TIFFSetField TIFFTAG_IMAGEWIDTH fails"));
   }
