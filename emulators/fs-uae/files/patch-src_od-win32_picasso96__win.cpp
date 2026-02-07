--- src/od-win32/picasso96_win.cpp.orig	2019-05-17 17:57:50 UTC
+++ src/od-win32/picasso96_win.cpp
@@ -3302,7 +3302,7 @@ static uae_u32 REGPARAM2 picasso_BlitRect (TrapContext
 	if (NOBLITTER_BLIT)
 		return 0;
 	P96TRACE((_T("BlitRect(%d, %d, %d, %d, %d, %d, 0x%x)\n"), srcx, srcy, dstx, dsty, width, height, Mask));
-	result = BlitRect (renderinfo, (uaecptr)NULL, srcx, srcy, dstx, dsty, width, height, Mask, BLIT_SRC);
+	result = BlitRect (renderinfo, (uaecptr)0, srcx, srcy, dstx, dsty, width, height, Mask, BLIT_SRC);
 	return result;
 }
 
