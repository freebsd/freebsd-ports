--- plugins/wpg/xp/ie_impGraphic_WPG.cpp.orig	2013-04-07 15:53:03.000000000 +0200
+++ plugins/wpg/xp/ie_impGraphic_WPG.cpp	2016-01-26 20:42:43.500548000 +0100
@@ -31,37 +31,43 @@
 #include <gsf/gsf-input-memory.h>
 #include <gsf/gsf-input-stdio.h>
 #include <gsf/gsf-infile-msole.h>
-#include <libwpd-stream/libwpd-stream.h>
+#include <gsf/gsf-infile-zip.h>
+#include <librevenge-stream/librevenge-stream.h>
 #include "xap_Module.h"
 
 using libwpg::WPGraphics;
 
 ABI_PLUGIN_DECLARE("WPG")
 
-class AbiWordPerfectGraphicsInputStream : public WPXInputStream
+class AbiWordPerfectGraphicsInputStream : public librevenge::RVNGInputStream
 {
 public:
 	AbiWordPerfectGraphicsInputStream(GsfInput *input);
 	~AbiWordPerfectGraphicsInputStream();
 
-	virtual bool isOLEStream();
-	virtual WPXInputStream * getDocumentOLEStream();
-	virtual WPXInputStream * getDocumentOLEStream(const char * name);
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
 
 AbiWordPerfectGraphicsInputStream::AbiWordPerfectGraphicsInputStream(GsfInput *input) :
-	WPXInputStream(),
+	librevenge::RVNGInputStream(),
 	m_input(input),
-	m_ole(NULL)
+	m_ole(NULL),
+	m_substreams()
 {
 	g_object_ref(G_OBJECT(input));
 }
@@ -86,45 +92,115 @@
 	return buf;
 }
 
-int AbiWordPerfectGraphicsInputStream::seek(long offset, WPX_SEEK_TYPE seekType) 
+int AbiWordPerfectGraphicsInputStream::seek(long offset, librevenge::RVNG_SEEK_TYPE seekType) 
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
 
-bool AbiWordPerfectGraphicsInputStream::isOLEStream()
+bool AbiWordPerfectGraphicsInputStream::isStructured()
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
 
-WPXInputStream * AbiWordPerfectGraphicsInputStream::getDocumentOLEStream()
+unsigned AbiWordPerfectGraphicsInputStream::subStreamCount()
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
 
-WPXInputStream * AbiWordPerfectGraphicsInputStream::getDocumentOLEStream(const char * name)
+const char * AbiWordPerfectGraphicsInputStream::subStreamName(unsigned id)
 {
-	WPXInputStream *documentStream = NULL;
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_msole_new (m_input, NULL)); 
+	
+	if (!m_ole)
+		m_ole = GSF_INFILE(gsf_infile_zip_new (m_input, NULL)); 
 	
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
+bool AbiWordPerfectGraphicsInputStream::existsSubStream(const char * name)
+{
 	if (!m_ole)
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
+librevenge::RVNGInputStream * AbiWordPerfectGraphicsInputStream::getSubStreamByName(const char * name)
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
@@ -138,12 +214,35 @@
 	return documentStream;
 }
 
+librevenge::RVNGInputStream * AbiWordPerfectGraphicsInputStream::getSubStreamById(unsigned id)
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
+					documentStream = new AbiWordPerfectGraphicsInputStream(document);
+					g_object_unref(G_OBJECT (document)); // the only reference should be encapsulated within the new stream
+				}
+		}
+	
+	return documentStream;
+}
+
 long AbiWordPerfectGraphicsInputStream::tell()
 {
 	return gsf_input_tell(m_input);
 }
 
-bool AbiWordPerfectGraphicsInputStream::atEOS()
+bool AbiWordPerfectGraphicsInputStream::isEnd()
 {
 	return gsf_input_eof(m_input);
 }
@@ -244,14 +343,24 @@
 UT_Error IE_Imp_WordPerfectGraphics::importGraphic(GsfInput *input, FG_Graphic **ppfg)
 {
 	AbiWordPerfectGraphicsInputStream gsfInput(input);
-	WPXString svgOutput;
-	if (WPGraphics::generateSVG(&gsfInput, svgOutput))
+	librevenge::RVNGString svgOutput;
+	librevenge::RVNGStringVector vec;
+	librevenge::RVNGSVGDrawingGenerator generator(vec, "");
+
+	if (!libwpg::WPGraphics::parse(&gsfInput, &generator) || vec.empty() || vec[0].empty())
 	{
-		GsfInput * svgInput = gsf_input_memory_new((const guint8*)svgOutput.cstr(), svgOutput.len(), false);
-		UT_Error result = IE_ImpGraphic::loadGraphic(svgInput, IE_ImpGraphic::fileTypeForSuffix(".svg"), ppfg);
-		g_object_unref(svgInput);
-		return result;
+		return UT_ERROR;
 	}
-	return UT_ERROR;
+
+	svgOutput.append("<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n");
+	svgOutput.append("<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"");
+	svgOutput.append(" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
+	svgOutput.append(vec[0]);
+	svgOutput.append("\n");
+
+	GsfInput * svgInput = gsf_input_memory_new((const guint8*)svgOutput.cstr(), svgOutput.len(), false);
+	UT_Error result = IE_ImpGraphic::loadGraphic(svgInput, IE_ImpGraphic::fileTypeForSuffix(".svg"), ppfg);
+	g_object_unref(svgInput);
+	return result;
 }
 
