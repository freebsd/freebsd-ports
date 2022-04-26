--- src/ES2FileFormat/Header/Reader/FKReader.h.orig	2021-11-25 00:56:57 UTC
+++ src/ES2FileFormat/Header/Reader/FKReader.h
@@ -42,21 +42,21 @@ class CFKReader : public IFKReader (public)
   m_nValidImageHeight = nHeight;
   m_bReadOnlyValidData = bReadOnlyValidData;
  }
- IFKDestination* GetCFkDestionation()
+ IFKDestination* GetCFkDestionation() override
  {
   return m_piFkDestination;
  }
  ESImageInfo& GetImageInfo(void);
  virtual void GetImageInfoAsJson(IESResultString& strJson) override;
- BOOL OpenWithDestination( IFKDestination* pcDestination, ENUM_FK_ERROR_CODE& eError );
- BOOL OpenWithDestinationAsJson( IFKDestination* pcDestination, ES_CHAR_CPTR pszOptionAsJson, ENUM_FK_ERROR_CODE& eError );
- virtual BOOL AppendSource(IFKSource* source, ENUM_FK_ERROR_CODE& eError);
- BOOL CloseAndReturnError( ENUM_FK_ERROR_CODE& eError );
- BOOL CloseWithOptionAsJson( ES_CHAR_CPTR pszOptionAsJson, ENUM_FK_ERROR_CODE& eError );
- virtual BOOL OpenReaderWithOptionAsJson( ES_CHAR_CPTR pszOptionAsJson, ENUM_FK_ERROR_CODE& eError ) = 0;
- virtual BOOL AppendSourceToReader( IFKSource* pcSource, ENUM_FK_ERROR_CODE& eError ) = 0;
- virtual BOOL CloseReaderWithOptionAsJson( ES_CHAR_CPTR pszOptionAsJson, ENUM_FK_ERROR_CODE& eError ) = 0;
- void Destroy(){
+ BOOL OpenWithDestination( IFKDestination* pcDestination, ENUM_FK_ERROR_CODE& eError ) override;
+ BOOL OpenWithDestinationAsJson( IFKDestination* pcDestination, ES_CHAR_CPTR pszOptionAsJson, ENUM_FK_ERROR_CODE& eError ) override;
+ virtual BOOL AppendSource(IFKSource* source, ENUM_FK_ERROR_CODE& eError) override;
+ BOOL CloseAndReturnError( ENUM_FK_ERROR_CODE& eError ) override;
+ BOOL CloseWithOptionAsJson( ES_CHAR_CPTR pszOptionAsJson, ENUM_FK_ERROR_CODE& eError ) override;
+ virtual BOOL OpenReaderWithOptionAsJson( ES_CHAR_CPTR pszOptionAsJson, ENUM_FK_ERROR_CODE& eError ) override = 0;
+ virtual BOOL AppendSourceToReader( IFKSource* pcSource, ENUM_FK_ERROR_CODE& eError ) override = 0;
+ virtual BOOL CloseReaderWithOptionAsJson( ES_CHAR_CPTR pszOptionAsJson, ENUM_FK_ERROR_CODE& eError ) override = 0;
+ void Destroy() override {
   delete this;
  }
 };
