--- sw/source/core/view/vprint.cxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ sw/source/core/view/vprint.cxx	2014-02-25 12:20:50.000000000 -0500
@@ -172,7 +172,7 @@
     }
 }
 
-void SetSwVisArea( ViewShell *pSh, const SwRect &rRect, sal_Bool /*bPDFExport*/ )
+void SetSwVisArea( ViewShell *pSh, const SwRect &rRect )
 {
     OSL_ENSURE( !pSh->GetWin(), "Drucken mit Window?" );
     pSh->maVisArea = rRect;
