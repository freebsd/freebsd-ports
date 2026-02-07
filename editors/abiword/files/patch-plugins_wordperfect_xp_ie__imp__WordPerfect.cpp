--- plugins/wordperfect/xp/ie_imp_WordPerfect.cpp.orig	2013-04-07 15:53:03.000000000 +0200
+++ plugins/wordperfect/xp/ie_imp_WordPerfect.cpp	2016-01-26 21:47:24.995046000 +0100
@@ -31,6 +31,8 @@
 #include <stdlib.h>
 #include <string.h>
 #include <math.h>
+#include <map>
+#include <string>
 #include <gsf/gsf-utils.h>
 #include <gsf/gsf-input-memory.h>
 #include <gsf/gsf-input-stdio.h>
@@ -60,42 +62,47 @@
 
 // Stream class
 
-#include <libwpd-stream/libwpd-stream.h>
+#include <librevenge-stream/librevenge-stream.h>
+#include <libwpd/libwpd.h>
 
 #include <gsf/gsf-input.h>
 #include <gsf/gsf-infile.h>
 #include <gsf/gsf-infile-msole.h>
+#include <gsf/gsf-infile-zip.h>
 
 #ifdef HAVE_LIBWPS
 #include <libwps/libwps.h>
 #endif
 
-class AbiWordperfectInputStream : public WPXInputStream
+class AbiWordperfectInputStream : public librevenge::RVNGInputStream
 {
 public:
 	AbiWordperfectInputStream(GsfInput *input);
 	~AbiWordperfectInputStream();
 
-	virtual bool isOLEStream();
-	virtual WPXInputStream * getDocumentOLEStream();
-
-	virtual WPXInputStream * getDocumentOLEStream(const char * name);
-
+	virtual bool isStructured();
+	virtual unsigned subStreamCount();
+	virtual const char* subStreamName(unsigned);
+	bool existsSubStream(const char*);
+	virtual librevenge::RVNGInputStream* getSubStreamByName(const char*);
+	virtual librevenge::RVNGInputStream* getSubStreamById(unsigned);
 	virtual const unsigned char *read(unsigned long numBytes, unsigned long &numBytesRead);
-	virtual int seek(long offset, WPX_SEEK_TYPE seekType);
+	virtual int seek(long offset, librevenge::RVNG_SEEK_TYPE seekType);
 	virtual long tell();
-	virtual bool atEOS();
+	virtual bool isEnd();
 
 private:
 
 	GsfInput *m_input;
 	GsfInfile *m_ole;
+	std::map<unsigned, std::string> m_substreams;
 };
 
 AbiWordperfectInputStream::AbiWordperfectInputStream(GsfInput *input) :
-	WPXInputStream(),
+	librevenge::RVNGInputStream(),
 	m_input(input),
-	m_ole(NULL)
+	m_ole(NULL),
+	m_substreams()
 {
 	g_object_ref(G_OBJECT(input));
 }
@@ -120,45 +127,115 @@ const unsigned char * AbiWordperfectInpu
 	return buf;
 }
 
-int AbiWordperfectInputStream::seek(long offset, WPX_SEEK_TYPE seekType) 
+int AbiWordperfectInputStream::seek(long offset, librevenge::RVNG_SEEK_TYPE seekType) 
 {
 	GSeekType gsfSeekType = G_SEEK_SET;
 	switch(seekType)
 	{
-	case WPX_SEEK_CUR:
+	case librevenge::RVNG_SEEK_CUR:
 		gsfSeekType = G_SEEK_CUR;
 		break;
-	case WPX_SEEK_SET:
+	case librevenge::RVNG_SEEK_SET:
 		gsfSeekType = G_SEEK_SET;
 		break;
+	case librevenge::RVNG_SEEK_END:
+		gsfSeekType = G_SEEK_END;
+		break;
 	}
 
 	return gsf_input_seek(m_input, offset, gsfSeekType);
 }
 
-bool AbiWordperfectInputStream::isOLEStream()
+bool AbiWordperfectInputStream::isStructured()
 {
 	if (!m_ole)
 		m_ole = GSF_INFILE(gsf_infile_msole_new (m_input, NULL)); 
 
-	if (m_ole != NULL)
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_zip_new (m_input, NULL)); 
+	
+	if (m_ole)
 		return true;
 
 	return false;
 }
 
-WPXInputStream * AbiWordperfectInputStream::getDocumentOLEStream()
+unsigned AbiWordperfectInputStream::subStreamCount()
 {
-	return getDocumentOLEStream("PerfectOffice_MAIN");
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_msole_new (m_input, NULL)); 
+	
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_zip_new (m_input, NULL)); 
+	
+	if (m_ole)
+		{
+			int numChildren = gsf_infile_num_children(m_ole);
+			if (numChildren > 0)
+				return numChildren;
+			return 0;
+		}
+	
+	return 0;
 }
 
-WPXInputStream * AbiWordperfectInputStream::getDocumentOLEStream(const char * name)
+const char * AbiWordperfectInputStream::subStreamName(unsigned id)
 {
-	WPXInputStream *documentStream = NULL;
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_msole_new (m_input, NULL)); 
 	
 	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_zip_new (m_input, NULL)); 
+	
+	if (m_ole)
+		{
+			if ((int)id >= gsf_infile_num_children(m_ole))
+			{
+				return 0;
+			}
+			std::map<unsigned, std::string>::iterator i = m_substreams.lower_bound(id);
+			if (i == m_substreams.end() || m_substreams.key_comp()(id, i->first))
+				{
+					std::string name = gsf_infile_name_by_index(m_ole, (int)id);
+					i = m_substreams.insert(i, std::map<unsigned, std::string>::value_type(id, name));
+				}
+			return i->second.c_str();
+		}
+	
+	return 0;
+}
+
+bool AbiWordperfectInputStream::existsSubStream(const char * name)
+{
+	if (!m_ole)
 		m_ole = GSF_INFILE(gsf_infile_msole_new (m_input, NULL)); 
 	
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_zip_new (m_input, NULL)); 
+	
+	if (m_ole)
+		{
+			GsfInput *document = gsf_infile_child_by_name(m_ole, name);
+			if (document) 
+				{
+					g_object_unref(G_OBJECT (document));
+					return true;
+				}
+		}
+	
+	return false;
+}
+
+librevenge::RVNGInputStream * AbiWordperfectInputStream::getSubStreamByName(const char * name)
+{
+	librevenge::RVNGInputStream *documentStream = NULL;
+	
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_msole_new (m_input, NULL)); 
+	
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_zip_new (m_input, NULL)); 
+	
 	if (m_ole)
 		{
 			GsfInput *document = gsf_infile_child_by_name(m_ole, name);
@@ -172,12 +249,35 @@ WPXInputStream * AbiWordperfectInputStre
 	return documentStream;
 }
 
+librevenge::RVNGInputStream * AbiWordperfectInputStream::getSubStreamById(unsigned id)
+{
+	librevenge::RVNGInputStream *documentStream = NULL;
+	
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_msole_new (m_input, NULL)); 
+	
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_zip_new (m_input, NULL)); 
+	
+	if (m_ole)
+		{
+			GsfInput *document = gsf_infile_child_by_index(m_ole, (int)id);
+			if (document) 
+				{
+					documentStream = new AbiWordperfectInputStream(document);
+					g_object_unref(G_OBJECT (document)); // the only reference should be encapsulated within the new stream
+				}
+		}
+	
+	return documentStream;
+}
+
 long AbiWordperfectInputStream::tell()
 {
 	return gsf_input_tell(m_input);
 }
 
-bool AbiWordperfectInputStream::atEOS()
+bool AbiWordperfectInputStream::isEnd()
 {
 	return gsf_input_eof(m_input);
 }
@@ -247,13 +347,13 @@ UT_Confidence_t IE_Imp_WordPerfect_Sniff
 {
 	AbiWordperfectInputStream gsfInput(input);
 
-	WPDConfidence confidence = WPDocument::isFileFormatSupported(&gsfInput);
-
+	libwpd::WPDConfidence confidence = libwpd::WPDocument::isFileFormatSupported(&gsfInput);
+	
 	switch (confidence)
 	{
-		case WPD_CONFIDENCE_NONE:
+		case libwpd::WPD_CONFIDENCE_NONE:
 			return UT_CONFIDENCE_ZILCH;
-		case WPD_CONFIDENCE_EXCELLENT:
+		case libwpd::WPD_CONFIDENCE_EXCELLENT:
 			return UT_CONFIDENCE_PERFECT;
 		default:
 			return UT_CONFIDENCE_ZILCH;
@@ -312,9 +412,9 @@ IE_Imp_WordPerfect::~IE_Imp_WordPerfect(
 UT_Error IE_Imp_WordPerfect::_loadFile(GsfInput * input)
 {
 	AbiWordperfectInputStream gsfInput(input);
-	WPDResult error = WPDocument::parse(&gsfInput, static_cast<WPXDocumentInterface *>(this), NULL);
+	libwpd::WPDResult error = libwpd::WPDocument::parse(&gsfInput, static_cast<librevenge::RVNGTextInterface *>(this), NULL);
 
-	if (error != WPD_OK)
+	if (error != libwpd::WPD_OK)
 	{
 		UT_DEBUGMSG(("AbiWordPerfect: ERROR: %i!\n", (int)error));
 		return UT_IE_IMPORTERROR;
@@ -329,7 +429,7 @@ void IE_Imp_WordPerfect::pasteFromBuffer
 	// nada
 }
 
-void IE_Imp_WordPerfect::setDocumentMetaData(const WPXPropertyList &propList)
+void IE_Imp_WordPerfect::setDocumentMetaData(const librevenge::RVNGPropertyList &propList)
 {
 	if (propList["dc:author"])
 		getDoc()->setMetaDataProp(PD_META_KEY_CREATOR, propList["dc:author"]->getStr().cstr());
@@ -339,15 +439,15 @@ void IE_Imp_WordPerfect::setDocumentMeta
 		getDoc()->setMetaDataProp(PD_META_KEY_PUBLISHER, propList["dc:publisher"]->getStr().cstr());
 	if (propList["dc:type"])
 		getDoc()->setMetaDataProp(PD_META_KEY_TYPE, propList["dc:category"]->getStr().cstr());
-	if (propList["libwpd:keywords"])
-		getDoc()->setMetaDataProp(PD_META_KEY_KEYWORDS, propList["libwpd:keywords"]->getStr().cstr());
+	if (propList["librevenge:keywords"])
+		getDoc()->setMetaDataProp(PD_META_KEY_KEYWORDS, propList["librevenge:keywords"]->getStr().cstr());
 	if (propList["dc:language"])
 		getDoc()->setMetaDataProp(PD_META_KEY_LANGUAGE, propList["dc:language"]->getStr().cstr());
-	if (propList["libwpd:abstract"])
-		getDoc()->setMetaDataProp(PD_META_KEY_DESCRIPTION, propList["libwpd:abstract"]->getStr().cstr());
+	if (propList["librevenge:abstract"])
+		getDoc()->setMetaDataProp(PD_META_KEY_DESCRIPTION, propList["librevenge:abstract"]->getStr().cstr());
 }
 
-void IE_Imp_WordPerfect::startDocument()
+void IE_Imp_WordPerfect::startDocument(const librevenge::RVNGPropertyList & /* propList */)
 {
 	UT_DEBUGMSG(("AbiWordPerfect: startDocument\n"));
 }
@@ -357,7 +457,7 @@ void IE_Imp_WordPerfect::endDocument()
 	UT_DEBUGMSG(("AbiWordPerfect: endDocument\n"));
 }
 
-void IE_Imp_WordPerfect::openPageSpan(const WPXPropertyList &propList)
+void IE_Imp_WordPerfect::openPageSpan(const librevenge::RVNGPropertyList &propList)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	UT_DEBUGMSG(("AbiWordPerfect: openPageSpan\n"));
@@ -378,7 +478,7 @@ void IE_Imp_WordPerfect::openPageSpan(co
 		
 }
 
-void IE_Imp_WordPerfect::openHeader(const WPXPropertyList & /*propList*/)
+void IE_Imp_WordPerfect::openHeader(const librevenge::RVNGPropertyList & /*propList*/)
 {
 	m_bHdrFtrOpenCount++;
 	
@@ -420,7 +520,7 @@ void IE_Imp_WordPerfect::closeHeader()
 	*/
 }
 
-void IE_Imp_WordPerfect::openFooter(const WPXPropertyList & /*propList*/)
+void IE_Imp_WordPerfect::openFooter(const librevenge::RVNGPropertyList & /*propList*/)
 {
 	m_bHdrFtrOpenCount++;
 	// see above comments re: openHeader
@@ -432,7 +532,7 @@ void IE_Imp_WordPerfect::closeFooter()
 	// see above comments re: closeHeader
 }
 
-void IE_Imp_WordPerfect::openParagraph(const WPXPropertyList &propList, const WPXPropertyListVector &tabStops)
+void IE_Imp_WordPerfect::openParagraph(const librevenge::RVNGPropertyList &propList)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	UT_DEBUGMSG(("AbiWordPerfect: openParagraph()\n"));
@@ -478,13 +578,15 @@ void IE_Imp_WordPerfect::openParagraph(c
 		(int)(m_topMargin*72), (int)(m_bottomMargin*72), m_leftMarginOffset, m_rightMarginOffset, m_textIndent, lineSpacing);
 	propBuffer += tmpBuffer;
 	
-	if (tabStops.count() > 0) // Append the tabstop information
+	const librevenge::RVNGPropertyListVector *tabStops = propList.child("style:tab-stops");
+	
+	if (tabStops && tabStops->count()) // Append the tabstop information
 	{
 		propBuffer += "; tabstops:";
 		tmpBuffer = "";
-                WPXPropertyListVector::Iter i(tabStops);
-                for (i.rewind(); i.next();)
-                {
+		librevenge::RVNGPropertyListVector::Iter i(*tabStops);
+		for (i.rewind(); i.next();)
+		{
 			propBuffer += tmpBuffer;
 			if (i()["style:position"])
 			{
@@ -515,8 +617,8 @@ void IE_Imp_WordPerfect::openParagraph(c
 				propBuffer += "0";
 
 			tmpBuffer = ",";
-                }
-        }
+		}
+	}
 
 	
 
@@ -543,7 +645,7 @@ void IE_Imp_WordPerfect::openParagraph(c
 	}
 }
 
-void IE_Imp_WordPerfect::openSpan(const WPXPropertyList &propList)
+void IE_Imp_WordPerfect::openSpan(const librevenge::RVNGPropertyList &propList)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	UT_DEBUGMSG(("AbiWordPerfect: Appending current text properties\n"));
@@ -614,13 +716,14 @@ void IE_Imp_WordPerfect::openSpan(const 
 	X_CheckDocumentError(appendFmt(propsArray));
 }
 
-void IE_Imp_WordPerfect::openSection(const WPXPropertyList &propList, const WPXPropertyListVector &columns)
+void IE_Imp_WordPerfect::openSection(const librevenge::RVNGPropertyList &propList)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	UT_DEBUGMSG(("AbiWordPerfect: openSection\n"));
 
 	float marginLeft = 0.0f, marginRight = 0.0f;
-	int columnsCount = ((columns.count() == 0) ? 1 : columns.count());
+	const librevenge::RVNGPropertyListVector *columns = propList.child("style:columns");
+	int columnsCount = ((!columns || !columns->count()) ? 1 : columns->count());
 
 	// TODO: support spaceAfter
 	if (propList["fo:start-indent"])
@@ -647,7 +750,7 @@ void IE_Imp_WordPerfect::insertTab()
 	X_CheckDocumentError(appendSpan(&ucs,1));	
 }
 
-void IE_Imp_WordPerfect::insertText(const WPXString &text)
+void IE_Imp_WordPerfect::insertText(const librevenge::RVNGString &text)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	if (text.len())
@@ -658,6 +761,15 @@ void IE_Imp_WordPerfect::insertText(cons
 	}
 }
 
+void IE_Imp_WordPerfect::insertSpace()
+{
+	if (m_bHdrFtrOpenCount) return; // HACK
+	UT_DEBUGMSG(("AbiWordPerfect: insertSpace\n"));
+
+	UT_UCS4Char ucs = UCS_SPACE;
+	X_CheckDocumentError(appendSpan(&ucs,1));	
+}
+
 void IE_Imp_WordPerfect::insertLineBreak()
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
@@ -668,24 +780,23 @@ void IE_Imp_WordPerfect::insertLineBreak
 }
 
 
-
-void IE_Imp_WordPerfect::defineOrderedListLevel(const WPXPropertyList &propList)
+void IE_Imp_WordPerfect::openOrderedListLevel(const librevenge::RVNGPropertyList &propList)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
-	UT_DEBUGMSG(("AbiWordPerfect: defineOrderedListLevel\n"));
-
+	UT_DEBUGMSG(("AbiWordPerfect: openOrderedListLevel\n"));
+	
 	int listID = 0, startingNumber = 0, level = 1;
 	char listType = '1';
 	UT_UTF8String textBeforeNumber, textAfterNumber;
 	float listLeftOffset = 0.0f;
 	float listMinLabelWidth = 0.0f;
 	
-	if (propList["libwpd:id"])
-		listID = propList["libwpd:id"]->getInt();
+	if (propList["librevenge:id"])
+		listID = propList["librevenge:id"]->getInt();
 	if (propList["text:start-value"])
 		startingNumber = propList["text:start-value"]->getInt();
-	if (propList["libwpd:level"])
-		level = propList["libwpd:level"]->getInt();
+	if (propList["librevenge:level"])
+		level = propList["librevenge:level"]->getInt();
 	if (propList["style:num-prefix"])
 		textBeforeNumber += propList["style:num-prefix"]->getStr().cstr();
 	if (propList["style:num-suffix"])
@@ -716,22 +827,38 @@ void IE_Imp_WordPerfect::defineOrderedLi
 		m_pCurrentListDefinition->setListMinLabelWidth(level, listMinLabelWidth);
 		_updateDocumentOrderedListDefinition(m_pCurrentListDefinition, level, listType, textBeforeNumber, textAfterNumber, startingNumber);
 	}
+
+	m_iCurrentListLevel++;
 }
 
-void IE_Imp_WordPerfect::defineUnorderedListLevel(const WPXPropertyList &propList)
+void IE_Imp_WordPerfect::closeOrderedListLevel()
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
-	UT_DEBUGMSG(("AbiWordPerfect: defineUnorderedListLevel\n"));
+	UT_DEBUGMSG(("AbiWordPerfect: closeOrderedListLevel (level: %i)\n", m_iCurrentListLevel));
+	UT_ASSERT(m_iCurrentListLevel > 0); 
+	
+	// every time we close a list level, the level above it is normally renumbered to start at "1"
+	// again. this code takes care of that.
+	if (m_iCurrentListLevel < (WP6_NUM_LIST_LEVELS-1))
+		m_pCurrentListDefinition->setLevelNumber(m_iCurrentListLevel + 1, 0);
+	
+	m_iCurrentListLevel--;
+}
 
+void IE_Imp_WordPerfect::openUnorderedListLevel(const librevenge::RVNGPropertyList &propList)
+{
+	if (m_bHdrFtrOpenCount) return; // HACK
+	UT_DEBUGMSG(("AbiWordPerfect: openUNorderedListLevel\n"));
+	
 	int listID = 0, level = 1;
-	WPXString textBeforeNumber, textAfterNumber;
+	librevenge::RVNGString textBeforeNumber, textAfterNumber;
 	float listLeftOffset = 0.0f;
 	float listMinLabelWidth = 0.0f;
 	
-	if (propList["libwpd:id"])
-		listID = propList["libwpd:id"]->getInt();
-	if (propList["libwpd:level"])
-		level = propList["libwpd:level"]->getInt();
+	if (propList["librevenge:id"])
+		listID = propList["librevenge:id"]->getInt();
+	if (propList["librevenge:level"])
+		level = propList["librevenge:level"]->getInt();
 	if (propList["text:space-before"])
 		listLeftOffset = propList["text:space-before"]->getDouble();
 	if (propList["text:min-label-width"])
@@ -752,36 +879,7 @@ void IE_Imp_WordPerfect::defineUnordered
 		m_pCurrentListDefinition->setListMinLabelWidth(level, listMinLabelWidth);
 		_updateDocumentUnorderedListDefinition(m_pCurrentListDefinition, level);
 	}
-}
 
-//void IE_Imp_WordPerfect::openOrderedListLevel(const int listID)
-void IE_Imp_WordPerfect::openOrderedListLevel(const WPXPropertyList & /*propList*/)
-{
-	if (m_bHdrFtrOpenCount) return; // HACK
-	UT_DEBUGMSG(("AbiWordPerfect: openOrderedListLevel\n"));
-	
-	m_iCurrentListLevel++;
-}
-
-void IE_Imp_WordPerfect::closeOrderedListLevel()
-{
-	if (m_bHdrFtrOpenCount) return; // HACK
-	UT_DEBUGMSG(("AbiWordPerfect: closeOrderedListLevel (level: %i)\n", m_iCurrentListLevel));
-	UT_ASSERT(m_iCurrentListLevel > 0); 
-	
-	// every time we close a list level, the level above it is normally renumbered to start at "1"
-	// again. this code takes care of that.
-	if (m_iCurrentListLevel < (WP6_NUM_LIST_LEVELS-1))
-		m_pCurrentListDefinition->setLevelNumber(m_iCurrentListLevel + 1, 0);
-	
-	m_iCurrentListLevel--;
-}
-
-void IE_Imp_WordPerfect::openUnorderedListLevel(const WPXPropertyList & /*propList*/)
-{
-	if (m_bHdrFtrOpenCount) return; // HACK
-	UT_DEBUGMSG(("AbiWordPerfect: openUNorderedListLevel\n"));
-	
 	m_iCurrentListLevel++;
 }
 
@@ -796,7 +894,7 @@ void IE_Imp_WordPerfect::closeUnorderedL
 
 // ASSUMPTION: We assume that unordered lists will always pass a number of "0". unpredictable behaviour
 // may result otherwise
-void IE_Imp_WordPerfect::openListElement(const WPXPropertyList &propList, const WPXPropertyListVector & /*tabStops*/)
+void IE_Imp_WordPerfect::openListElement(const librevenge::RVNGPropertyList &propList)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	UT_DEBUGMSG(("AbiWordPerfect: openListElement\n"));
@@ -885,7 +983,7 @@ void IE_Imp_WordPerfect::openListElement
 	X_CheckDocumentError(appendSpan(&ucs,1));
 }
 
-void IE_Imp_WordPerfect::openFootnote(const WPXPropertyList & /*propList*/)
+void IE_Imp_WordPerfect::openFootnote(const librevenge::RVNGPropertyList & /*propList*/)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 
@@ -934,7 +1032,7 @@ void IE_Imp_WordPerfect::closeFootnote()
 	X_CheckDocumentError(appendStrux(PTX_EndFootnote,NULL));
 }
 
-void IE_Imp_WordPerfect::openEndnote(const WPXPropertyList & /*propList*/)
+void IE_Imp_WordPerfect::openEndnote(const librevenge::RVNGPropertyList & /*propList*/)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	const gchar** propsArray = NULL;
@@ -975,7 +1073,7 @@ void IE_Imp_WordPerfect::closeEndnote()
 	X_CheckDocumentError(appendStrux(PTX_EndEndnote,NULL));
 }
 
-void IE_Imp_WordPerfect::openTable(const WPXPropertyList &propList, const WPXPropertyListVector &columns)
+void IE_Imp_WordPerfect::openTable(const librevenge::RVNGPropertyList &propList)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	// TODO: handle 'marginLeftOffset' and 'marginRightOffset'
@@ -1000,14 +1098,18 @@ void IE_Imp_WordPerfect::openTable(const
 		}
 	}
 	
-	propBuffer += "table-column-props:";
-	WPXPropertyListVector::Iter i(columns);
-	for (i.rewind(); i.next();)
-	{
-		UT_String tmpBuffer;
-		if (i()["style:column-width"])
-			UT_String_sprintf(tmpBuffer, "%s/", i()["style:column-width"]->getStr().cstr());
-		propBuffer += tmpBuffer;
+	const librevenge::RVNGPropertyListVector *columns = propList.child("librevenge:table-columns");
+	if (columns)
+	{
+		propBuffer += "table-column-props:";
+		librevenge::RVNGPropertyListVector::Iter i(*columns);
+		for (i.rewind(); i.next();)
+		{
+			UT_String tmpBuffer;
+			if (i()["style:column-width"])
+				UT_String_sprintf(tmpBuffer, "%s/", i()["style:column-width"]->getStr().cstr());
+			propBuffer += tmpBuffer;
+		}
 	}
 
 	const gchar* propsArray[3];
@@ -1018,7 +1120,7 @@ void IE_Imp_WordPerfect::openTable(const
 	X_CheckDocumentError(appendStrux(PTX_SectionTable, propsArray));
 }
 
-void IE_Imp_WordPerfect::openTableRow(const WPXPropertyList & /*propList*/)
+void IE_Imp_WordPerfect::openTableRow(const librevenge::RVNGPropertyList & /*propList*/)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	UT_DEBUGMSG(("AbiWordPerfect: openRow\n"));
@@ -1030,14 +1132,14 @@ void IE_Imp_WordPerfect::openTableRow(co
 	m_bInCell = false;
 }
 
-void IE_Imp_WordPerfect::openTableCell(const WPXPropertyList &propList)
+void IE_Imp_WordPerfect::openTableCell(const librevenge::RVNGPropertyList &propList)
 {
 	if (m_bHdrFtrOpenCount) return; // HACK
 	int col =0,  row = 0, colSpan = 0, rowSpan = 0;
-	if (propList["libwpd:column"])
-		col = propList["libwpd:column"]->getInt();
-	if (propList["libwpd:row"])
-		row = propList["libwpd:row"]->getInt();
+	if (propList["librevenge:column"])
+		col = propList["librevenge:column"]->getInt();
+	if (propList["librevenge:row"])
+		row = propList["librevenge:row"]->getInt();
 	if (propList["table:number-columns-spanned"])
 		colSpan = propList["table:number-columns-spanned"]->getInt();
 	if (propList["table:number-rows-spanned"])
@@ -1247,9 +1349,9 @@ protected:
     virtual UT_Error _loadFile(GsfInput * input)
 	{
 		AbiWordperfectInputStream gsfInput(input);
-		WPSResult error = WPSDocument::parse(&gsfInput, static_cast<WPXDocumentInterface *>(this));
+		libwps::WPSResult error = libwps::WPSDocument::parse(&gsfInput, static_cast<librevenge::RVNGTextInterface *>(this), NULL, NULL);
 
-		if (error != WPS_OK)
+		if (error != libwps::WPS_OK)
 			{
 				UT_DEBUGMSG(("AbiMSWorks: ERROR: %i!\n", (int)error));
 				return UT_IE_IMPORTERROR;
@@ -1286,13 +1388,19 @@ UT_Confidence_t IE_Imp_MSWorks_Sniffer::
 {
 	AbiWordperfectInputStream gsfInput(input);
 
-	WPSConfidence confidence = WPSDocument::isFileFormatSupported(&gsfInput);
+	libwps::WPSCreator creator;
+	libwps::WPSKind kind;
+	bool needEncoding;
+	libwps::WPSConfidence confidence = libwps::WPSDocument::isFileFormatSupported(&gsfInput, kind, creator, needEncoding);
+	
+	if (kind != libwps::WPS_TEXT)
+		confidence = libwps::WPS_CONFIDENCE_NONE;
 
 	switch (confidence)
 	{
-		case WPS_CONFIDENCE_NONE:
+		case libwps::WPS_CONFIDENCE_NONE:
 			return UT_CONFIDENCE_ZILCH;
-		case WPS_CONFIDENCE_EXCELLENT:
+		case libwps::WPS_CONFIDENCE_EXCELLENT:
 			return UT_CONFIDENCE_PERFECT;
 		default:
 			return UT_CONFIDENCE_ZILCH;
