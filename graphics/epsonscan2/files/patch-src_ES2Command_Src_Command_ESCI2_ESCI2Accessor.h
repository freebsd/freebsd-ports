--- src/ES2Command/Src/Command/ESCI2/ESCI2Accessor.h.orig	2021-11-25 00:56:55 UTC
+++ src/ES2Command/Src/Command/ESCI2/ESCI2Accessor.h
@@ -37,7 +37,7 @@ class CESCI2Accessor : public CESCI2Command (protected
  ESErrorCode SetPanelToPushScanReady( BOOL bPushScanReady );
  ESErrorCode UnlockAdministratorLock();
  ESErrorCode LockAdministratorLock();
- bool RequestingUnlockAdminLock();
+ virtual bool RequestingUnlockAdminLock() override;
  BOOL IsScannableDeviceConfig();
  ESErrorCode CaptureScanner();
  ESErrorCode ReleaseScanner();
@@ -208,7 +208,7 @@ class CESCI2Accessor : public CESCI2Command (protected
  ESErrorCode _SetColorMatrix( ES_COLOR_MATRIX& matrix );
  ESErrorCode SetColorMatrix( ESFloatArray arColorMatrix );
  bool IsSkewCorrectionSupported();
- bool IsSkewCorrectionEnabled();
+ bool IsSkewCorrectionEnabled() override;
  ESErrorCode SetSkewCorrectionEnabled( bool bSkewCorrectionEnabled );
  ESAny GetSupportedThreshold();
  ESNumber GetThreshold();
@@ -226,7 +226,7 @@ class CESCI2Accessor : public CESCI2Command (protected
     ESNumber GetGammaScale();
     ESErrorCode SetGammaScale( ESNumber nGammaScale );
     ESAny GetSupportedBackGroundRemoval();
-    ESNumber GetBackGroundRemoval();
+    virtual ESNumber GetBackGroundRemoval() override;
     ESErrorCode SetBackGroundRemoval( ESNumber nBackGroundRemoval );
  ESAny GetSupportedJPEGQuality();
  ESNumber GetJPEGQuality();
@@ -235,7 +235,7 @@ class CESCI2Accessor : public CESCI2Command (protected
  ESQuietMode GetQuietMode();
  ESErrorCode SetQuietMode( ESNumber nQuietMode);
  bool IsAutoCroppingSupported();
- bool IsAutoCroppingEnabled();
+ virtual bool IsAutoCroppingEnabled() override;
  ESErrorCode SetAutoCroppingEnabled( bool bAutoCroppingEnabled );
  ESAny GetCroppableResolutions();
  ESAny GetSupportedCroppingSizes();
