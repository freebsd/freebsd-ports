--- vcl/source/gdi/print.cxx.orig	Thu Apr 17 18:58:42 2003
+++ vcl/source/gdi/print.cxx	Thu Apr 17 18:59:10 2003
@@ -532,7 +532,7 @@
 		if ( (pJobSetup->maPrinterName != pInfo->maPrinterName) ||
 			 (pJobSetup->maDriver != pInfo->maDriver) )
 		{
-			rtl_freeMemory( pJobSetup->mpDriverData );
+			delete pJobSetup->mpDriverData;
 			pJobSetup->mpDriverData = NULL;
 			pJobSetup->mnDriverDataLen = 0;
 		}
