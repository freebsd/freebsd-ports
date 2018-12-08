--- src/od-win32/picasso96_win.cpp.orig	2017-01-24 16:58:57 UTC
+++ src/od-win32/picasso96_win.cpp
@@ -3300,7 +3300,7 @@ static uae_u32 REGPARAM2 picasso_BlitRec
 	if (NOBLITTER_BLIT)
 		return 0;
 	P96TRACE((_T("BlitRect(%d, %d, %d, %d, %d, %d, 0x%x)\n"), srcx, srcy, dstx, dsty, width, height, Mask));
-	result = BlitRect (renderinfo, (uaecptr)NULL, srcx, srcy, dstx, dsty, width, height, Mask, BLIT_SRC);
+	result = BlitRect (renderinfo, (uaecptr)0, srcx, srcy, dstx, dsty, width, height, Mask, BLIT_SRC);
 	return result;
 }
 
