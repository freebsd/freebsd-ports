--- src/ES2FileFormat/Header/IO/FKDestination.h.orig	2021-11-25 00:56:57 UTC
+++ src/ES2FileFormat/Header/IO/FKDestination.h
@@ -33,12 +33,12 @@ class CFKDestination : public IFKDestination (private)
 public:
  CFKDestination();
  ~CFKDestination();
- FKDestinationType GetFKDestinationType()
+ FKDestinationType GetFKDestinationType() override
  {
   return m_eFKDestinationType;
  }
- ES_CMN_FUNCS::BUFFER::IESBuffer& GetSource();
- void SetDelegate(IFKDestinationDelegate* piDelegate){
+ ES_CMN_FUNCS::BUFFER::IESBuffer& GetSource() override;
+ void SetDelegate(IFKDestinationDelegate* piDelegate) override {
   m_pcDelegate = piDelegate ;
  }
  void SetUserData(const ESImageInfo& dictImageInfo){
@@ -50,10 +50,10 @@ class CFKDestination : public IFKDestination (private)
  virtual void SetUserDataAsJson(ES_CHAR_CPTR pszUserDataAsJson) override;
  virtual void GetUserDataAsJson(IESResultString& pszUserDataAsJson) override;
  static IFKDestination* CreateAndInitInstanceWithType( FKDestinationType eType, ES_CMN_FUNCS::BUFFER::IESBuffer& cSource );
- void NotifyDidBeginReceivingForImageInfo( ES_CHAR_CPTR pszImageInfoAsJson );
- void NotifyDidEndReceivingForImageInfo( ES_CHAR_CPTR pszImageInfoAsJson );
+ void NotifyDidBeginReceivingForImageInfo( ES_CHAR_CPTR pszImageInfoAsJson ) override;
+ void NotifyDidEndReceivingForImageInfo( ES_CHAR_CPTR pszImageInfoAsJson ) override;
  void NotifyReceiveImageData( ES_CMN_FUNCS::BUFFER::IESBuffer& cData, ES_CHAR_CPTR pszImageInfoAsJson ) override;
- void Destroy(){
+ void Destroy() override {
   delete this;
  }
 };
