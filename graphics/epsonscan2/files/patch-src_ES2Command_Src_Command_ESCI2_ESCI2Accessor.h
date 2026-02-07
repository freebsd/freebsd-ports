--- src/ES2Command/Src/Command/ESCI2/ESCI2Accessor.h.orig	2024-09-12 07:10:31 UTC
+++ src/ES2Command/Src/Command/ESCI2/ESCI2Accessor.h
@@ -34,7 +34,7 @@ class CESCI2Accessor : public CESCI2Command (protected
  ESErrorCode SetPanelToPushScanReady( BOOL bPushScanReady );
  ESErrorCode UnlockAdministratorLock();
  ESErrorCode LockAdministratorLock();
- bool RequestingUnlockAdminLock();
+ virtual bool RequestingUnlockAdminLock() override;
  BOOL IsScannableDeviceConfig();
  ESErrorCode CaptureScanner();
  ESErrorCode ReleaseScanner();
@@ -211,7 +211,7 @@ class CESCI2Accessor : public CESCI2Command (protected
  ESErrorCode _SetColorMatrix( ES_COLOR_MATRIX& matrix );
  ESErrorCode SetColorMatrix( ESFloatArray arColorMatrix );
  bool IsSkewCorrectionSupported();
- bool IsSkewCorrectionEnabled();
+ bool IsSkewCorrectionEnabled() override;
  ESErrorCode SetSkewCorrectionEnabled( bool bSkewCorrectionEnabled );
  ESAny GetSupportedThreshold();
  ESNumber GetThreshold();
@@ -241,7 +241,7 @@ class CESCI2Accessor : public CESCI2Command (protected
  virtual bool IsSkipImageEnabled();
  virtual ESErrorCode SetSkipImageEnabled( bool nDetectBlankPageLevel );
     ESAny GetSupportedBackGroundRemoval();
-    ESNumber GetBackGroundRemoval();
+    virtual ESNumber GetBackGroundRemoval() override;
     ESErrorCode SetBackGroundRemoval( ESNumber nBackGroundRemoval );
  ESErrorCode DoAutoFocus(ESFloat* pfOutFocus);
  bool IsAutoFocusSupported();
@@ -257,10 +257,10 @@ class CESCI2Accessor : public CESCI2Command (protected
  ESQuietMode GetQuietMode();
  ESErrorCode SetQuietMode( ESNumber nQuietMode);
  bool IsAutoCroppingSupported();
- bool IsAutoCroppingEnabled();
+ virtual bool IsAutoCroppingEnabled() override;
  ESErrorCode SetAutoCroppingEnabled( bool bAutoCroppingEnabled );
  bool IsAutoCroppingInscribedSupported();
- bool IsAutoCroppingInscribedEnabled();
+ bool IsAutoCroppingInscribedEnabled() override;
  ESErrorCode SetAutoCroppingInscribedEnabled( bool bAutoCroppingEnabled );
  ESAny GetCroppableResolutions();
  ESAny GetSupportedCroppingSizes();
@@ -516,7 +516,7 @@ class CESCI2Accessor : public CESCI2Command (protected
  bool IsRetardRollerNearendSupported();
  ESNumber GetRetardRollerNearend();
  ESAny GetSupportedCapability(const UInt32& key);
- ENUM_ES_HASH_TYPE GetMaintenanceHashType();
+ ENUM_ES_HASH_TYPE GetMaintenanceHashType() override;
 private :
  template <typename Function>
  void ForeachAnyArrayValue(const ESAny &anyValue, Function func) {
