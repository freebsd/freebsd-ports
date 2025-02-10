--- src/ES2FileFormat/Header/IO/FKSource.h.orig	2024-09-12 07:10:33 UTC
+++ src/ES2FileFormat/Header/IO/FKSource.h
@@ -37,7 +37,7 @@ class CFKSource : public IFKSource (public)
  {
   return m_bFull;
  }
- ES_CMN_FUNCS::BUFFER::IESBuffer& GetSource( );
+ ES_CMN_FUNCS::BUFFER::IESBuffer& GetSource( ) override;
  static IFKSource* CreateAndInitInstanceWithType(FKSourceType eSourceType, ES_CMN_FUNCS::BUFFER::IESBuffer& vpSource, BOOL bIsFull);
  void Destroy() override{
   delete this;
