--- ../sw/source/filter/rtf/swparrtf.cxx.orig	Thu Apr 17 22:51:18 2003
+++ ../sw/source/filter/rtf/swparrtf.cxx	Thu Apr 17 22:59:27 2003
@@ -3120,10 +3120,156 @@
 	SetSwgValues( rCollSet );
 }
 
+//Takashi Ono for CJK
+String SwRTFParser::XlateFmtColName( const String &rName )
+{
+#define RES_NONE RES_POOLCOLL_DOC_END
+
+	static const RES_POOL_COLLFMT_TYPE aArr[]={
+		RES_POOLCOLL_STANDARD, RES_POOLCOLL_HEADLINE1, RES_POOLCOLL_HEADLINE2,
+		RES_POOLCOLL_HEADLINE3, RES_POOLCOLL_HEADLINE4, RES_POOLCOLL_HEADLINE5,
+		RES_POOLCOLL_HEADLINE6, RES_POOLCOLL_HEADLINE7, RES_POOLCOLL_HEADLINE8,
+		RES_POOLCOLL_HEADLINE9,
+
+		RES_POOLCOLL_TOX_IDX1, RES_POOLCOLL_TOX_IDX2, RES_POOLCOLL_TOX_IDX3,
+		RES_NONE, RES_NONE, RES_NONE, RES_NONE, RES_NONE, RES_NONE,
+		RES_POOLCOLL_TOX_CNTNT1,
+
+		RES_POOLCOLL_TOX_CNTNT2, RES_POOLCOLL_TOX_CNTNT3, RES_POOLCOLL_TOX_CNTNT4,
+		RES_POOLCOLL_TOX_CNTNT5, RES_POOLCOLL_TOX_CNTNT6, RES_POOLCOLL_TOX_CNTNT7,
+		RES_POOLCOLL_TOX_CNTNT8, RES_POOLCOLL_TOX_CNTNT9,
+		RES_NONE, RES_POOLCOLL_FOOTNOTE,
+
+		RES_NONE, RES_POOLCOLL_HEADER, RES_POOLCOLL_FOOTER, RES_POOLCOLL_TOX_IDXH,
+		RES_NONE, RES_NONE, RES_POOLCOLL_JAKETADRESS, RES_POOLCOLL_SENDADRESS,
+		RES_NONE, RES_NONE,
+
+		RES_NONE, RES_NONE, RES_NONE, RES_POOLCOLL_ENDNOTE, RES_NONE, RES_NONE, RES_NONE,
+		RES_POOLCOLL_LISTS_BEGIN, RES_NONE, RES_NONE,
+
+		RES_NONE, RES_NONE, RES_NONE, RES_NONE, RES_NONE,
+		RES_NONE, RES_NONE, RES_NONE, RES_NONE, RES_NONE,
+
+		RES_NONE,RES_NONE, RES_POOLCOLL_DOC_TITEL, RES_NONE, RES_POOLCOLL_SIGNATURE, RES_NONE,
+		RES_POOLCOLL_TEXT, RES_POOLCOLL_TEXT_MOVE, RES_NONE, RES_NONE,
+
+		RES_NONE, RES_NONE, RES_NONE, RES_NONE, RES_POOLCOLL_DOC_SUBTITEL };
+	static const sal_Char *stiName[] = {
+		"Normal",
+		"heading 1",
+		"heading 2",
+		"heading 3",
+		"heading 4",
+		"heading 5",
+		"heading 6",
+		"heading 7",
+		"heading 8",
+		"heading 9",
+		"index 1",
+		"index 2",
+		"index 3",
+		"index 4",
+		"index 5",
+		"index 6",
+		"index 7",
+		"index 8",
+		"index 9",
+		"toc 1",
+		"toc 2",
+		"toc 3",
+		"toc 4",
+		"toc 5",
+		"toc 6",
+		"toc 7",
+		"toc 8",
+		"toc 9",
+		"Normal Indent",
+		"footnote text",
+		"annotation text",
+		"header",
+		"footer",
+		"index heading",
+		"caption",
+		"table of figures",
+		"envelope address",
+		"envelope return",
+		"footnote reference",
+		"annotation reference",
+		"line number",
+		"page number",
+		"endnote reference",
+		"endnote text",
+		"table of authorities",
+		"macro",
+		"toa heading",
+		"List",
+		"List Bullet",
+		"List Number",
+		"List 2",
+		"List 3",
+		"List 4",
+		"List 5",
+		"List Bullet 2",
+		"List Bullet 3",
+		"List Bullet 4",
+		"List Bullet 5",
+		"List Number 2",
+		"List Number 3",
+		"List Number 4",
+		"List Number 5",
+		"Title",
+		"Closing",
+		"Signature",
+		"Default Paragraph Font",
+		"Body Text",
+		"Body Text Indent",
+		"List Continue",
+		"List Continue 2",
+		"List Continue 3",
+		"List Continue 4",
+		"List Continue 5",
+		"Message Header",
+		"Subtitle",
+	};
+
+
+	ASSERT( ( sizeof( aArr ) / sizeof( RES_POOL_COLLFMT_TYPE ) == 75 ),
+			"Style-UEbersetzungstabelle hat falsche Groesse" );
+	ASSERT( ( sizeof( stiName ) / sizeof( *stiName ) == 75 ),
+			"Style-UEbersetzungstabelle hat falsche Groesse" );
+
+	RES_POOL_COLLFMT_TYPE nId = RES_NONE;
+
+	for (int i = 0; i < sizeof( stiName ) / sizeof( *stiName ); i++)
+	{
+		if ( rName == String( stiName[i], RTL_TEXTENCODING_MS_1252 ) )
+		{
+			nId = aArr[i];
+			break;
+		}
+	}
+	USHORT nResId;
+	if( RES_POOLCOLL_TEXT_BEGIN <= nId && nId < RES_POOLCOLL_TEXT_END )
+		nResId = RC_POOLCOLL_TEXT_BEGIN - RES_POOLCOLL_TEXT_BEGIN;
+	else if (RES_POOLCOLL_LISTS_BEGIN <= nId && nId < RES_POOLCOLL_LISTS_END)
+		nResId = RC_POOLCOLL_LISTS_BEGIN - RES_POOLCOLL_LISTS_BEGIN;
+	else if (RES_POOLCOLL_EXTRA_BEGIN <= nId && nId < RES_POOLCOLL_EXTRA_END)
+		nResId = RC_POOLCOLL_EXTRA_BEGIN - RES_POOLCOLL_EXTRA_BEGIN;
+	else if (RES_POOLCOLL_REGISTER_BEGIN <= nId && nId < RES_POOLCOLL_REGISTER_END)
+		nResId = RC_POOLCOLL_REGISTER_BEGIN - RES_POOLCOLL_REGISTER_BEGIN;
+	else if (RES_POOLCOLL_DOC_BEGIN <= nId && nId < RES_POOLCOLL_DOC_END)
+		nResId = RC_POOLCOLL_DOC_BEGIN - RES_POOLCOLL_DOC_BEGIN;
+	else if (RES_POOLCOLL_HTML_BEGIN <= nId && nId < RES_POOLCOLL_HTML_END)
+		nResId = RC_POOLCOLL_HTML_BEGIN - RES_POOLCOLL_HTML_BEGIN;
+	return String( ResId( nResId + nId, pSwResMgr ) );
+}
+
 SwTxtFmtColl* SwRTFParser::MakeStyle( USHORT nNo, const SvxRTFStyleType& rStyle )
 {
-	int bCollExist;
-	SwTxtFmtColl* pColl = MakeColl( rStyle.sName, USHORT(nNo),
+ 	int bCollExist;
+//	SwTxtFmtColl* pColl = MakeColl( rStyle.sName, USHORT(nNo),	//Takashi Ono for CJK
+	SwTxtFmtColl* pColl = MakeColl( XlateFmtColName( rStyle.sName ),
+									USHORT(nNo),
 									rStyle.nOutlineNo, bCollExist );
 	aTxtCollTbl.Insert( nNo, pColl );
 
