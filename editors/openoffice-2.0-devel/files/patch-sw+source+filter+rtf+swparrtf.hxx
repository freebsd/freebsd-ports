--- ../sw/source/filter/rtf/swparrtf.hxx.orig	Fri Feb  7 01:29:41 2003
+++ ../sw/source/filter/rtf/swparrtf.hxx	Thu Apr 17 22:57:18 2003
@@ -360,6 +360,7 @@
 	void SetStyleAttr( SfxItemSet& rCollSet,
 						const SfxItemSet& rStyleSet,
 						const SfxItemSet& rDerivedSet );
+	String XlateFmtColName( const String &rName );	//Takashi Ono for CJK
 	SwTxtFmtColl* MakeStyle( USHORT nNo, const SvxRTFStyleType& rStyle );
 	SwCharFmt* MakeCharStyle( USHORT nNo, const SvxRTFStyleType& rStyle );
 	void MakeStyleTab();
