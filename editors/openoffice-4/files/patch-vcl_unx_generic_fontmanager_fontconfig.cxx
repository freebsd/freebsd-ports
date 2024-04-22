--- vcl/unx/generic/fontmanager/fontconfig.cxx.orig	2020-10-06 14:16:35 UTC
+++ vcl/unx/generic/fontmanager/fontconfig.cxx
@@ -456,6 +456,7 @@ void FontCfgWrapper::addFontSet( FcSetName eSetName )
 		if( m_nFcVersion > 20400 ) // #i115204# avoid trouble with old FC versions
 		{
 			FcPattern* pTestPattern = FcPatternDuplicate( pOrigPattern );
+            FcDefaultSubstitute( pTestPattern );
 			FcPatternAddBool( pTestPattern, FC_OUTLINE, FcTrue );
 			// TODO: ignore all attributes that are not interesting for finding dupes
 			//       e.g. by using pattern->ImplFontAttr->pattern conversion
