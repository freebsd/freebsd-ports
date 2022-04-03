--- src/Controller/Src/Scanner/Engine.hpp.orig	2021-11-25 00:56:59 UTC
+++ src/Controller/Src/Scanner/Engine.hpp
@@ -357,14 +357,14 @@ namespace epsonscan {
   void CALLBACK ScannerDidWarmUp( IESScanner* pScanner ) override;
   void CALLBACK NetworkScannerDidRequestStartScanning( IESScanner* pScanner ) override;
   void CALLBACK NetworkScannerDidRequestStopScanning( IESScanner* pScanner ) override;
-  void CALLBACK ScannerDidDisconnect( IESScanner* pScanner ) ;
-  void CALLBACK NetworkScannerDidReceiveServerError(IESScanner* pScanner) ;
-  BOOL CALLBACK NetworkScannerShouldPreventTimeout( IESScanner* pScanner ) ;
-  void CALLBACK NetworkScannerDidTimeout( IESScanner* pScanner ) ;
-  void CALLBACK ScannerIsReservedByHost( IESScanner* pScanner, const ES_CHAR* pszAddress ) ;
-  void CALLBACK ScannerDidPressButton( UInt8 un8ButtonNumber ) ;
-  void CALLBACK ScannerDidRequestStop(IESScanner *pScanner);
-  void CALLBACK ScannerDidRequestPushScanConnection(IESScanner *pScanner);
-  void CALLBACK ScannerDidNotifyStatusChange(IESScanner *pScanner) ;
+  void CALLBACK ScannerDidDisconnect( IESScanner* pScanner ) override;
+  void CALLBACK NetworkScannerDidReceiveServerError(IESScanner* pScanner) override;
+  BOOL CALLBACK NetworkScannerShouldPreventTimeout( IESScanner* pScanner ) override;
+  void CALLBACK NetworkScannerDidTimeout( IESScanner* pScanner ) override;
+  void CALLBACK ScannerIsReservedByHost( IESScanner* pScanner, const ES_CHAR* pszAddress ) override;
+  void CALLBACK ScannerDidPressButton( UInt8 un8ButtonNumber ) override;
+  void CALLBACK ScannerDidRequestStop(IESScanner *pScanner) override;
+  void CALLBACK ScannerDidRequestPushScanConnection(IESScanner *pScanner) override;
+  void CALLBACK ScannerDidNotifyStatusChange(IESScanner *pScanner) override;
  };
 }
