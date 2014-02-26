--- sw/source/core/inc/frame.hxx.orig	2014-02-05 10:04:15.000000000 -0500
+++ sw/source/core/inc/frame.hxx	2014-02-25 12:20:50.000000000 -0500
@@ -234,7 +234,7 @@
     friend class SwLooping;
 
     // voids lower during creation of a column
-    friend SwFrm *SaveCntnt( SwLayoutFrm *, SwFrm* pStart = NULL );
+    friend SwFrm *SaveCntnt( SwLayoutFrm *, SwFrm* pStart );
     friend void   RestoreCntnt( SwFrm *, SwLayoutFrm *, SwFrm *pSibling, bool bGrow );
 
 #ifdef DBG_UTIL
