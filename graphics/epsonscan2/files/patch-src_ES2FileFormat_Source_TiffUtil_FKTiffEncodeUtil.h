--- src/ES2FileFormat/Source/TiffUtil/FKTiffEncodeUtil.h.orig	2024-09-12 07:10:33 UTC
+++ src/ES2FileFormat/Source/TiffUtil/FKTiffEncodeUtil.h
@@ -25,8 +25,8 @@ class FKTiffEncodeUtil (public)
 public:
  FKTiffEncodeUtil();
  virtual ~FKTiffEncodeUtil();
- BOOL StartWithPath(ESString& path, ESImageInfo& imageInfo, uint32 compression, BOOL appendMode,
- ESString& iccProfilePath, ENUM_FK_ERROR_CODE& eError,uint32 un32JpegQuality);
+ BOOL StartWithPath(ESString& path, ESImageInfo& imageInfo, uint32_t compression, BOOL appendMode,
+ ESString& iccProfilePath, ENUM_FK_ERROR_CODE& eError,uint32_t un32JpegQuality);
  virtual BOOL WriteScanlinesWithData(const ES_CMN_FUNCS::BUFFER::IESBuffer& cData, ENUM_FK_ERROR_CODE& eError);
  virtual BOOL FinalizeAndReturnError(ENUM_FK_ERROR_CODE& eError);
 protected:
