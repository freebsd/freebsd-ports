--- src/text/fmt/xp/fv_View_protected.cpp.orig	2021-07-03 15:46:07 UTC
+++ src/text/fmt/xp/fv_View_protected.cpp
@@ -5752,7 +5752,7 @@ UT_UCSChar * FV_View::_lookupSuggestion(fl_BlockLayout
 		UT_uint32 len = iLength;
 		for (UT_uint32 ldex=0; ldex < len && ldex < INPUTWORDLEN; ldex++)
 		{
-			stMisspelledWord += *pWord == UCS_RQUOTE ? '\'' : *pWord;
+			stMisspelledWord += *pWord == UCS_RQUOTE ? U'\'' : *pWord;
 			++pWord;
 		}
 
