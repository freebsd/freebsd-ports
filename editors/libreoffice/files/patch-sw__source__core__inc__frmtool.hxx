--- sw/source/core/inc/frmtool.hxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ sw/source/core/inc/frmtool.hxx	2014-02-25 12:20:50.000000000 -0500
@@ -70,7 +70,7 @@
 
 sal_uLong SqRt( BigInt nX );
 
-SwFrm *SaveCntnt( SwLayoutFrm *pLay, SwFrm *pStart );
+SwFrm *SaveCntnt( SwLayoutFrm *pLay, SwFrm *pStart = NULL );
 void RestoreCntnt( SwFrm *pSav, SwLayoutFrm *pParent, SwFrm *pSibling, bool bGrow );
 
 // Get CntntNodes, create CntntFrms, and add them to LayFrm.
