--- libs/tex/io/tiffdirhandle.cpp.orig	2012-02-20 18:04:48.000000000 +0300
+++ libs/tex/io/tiffdirhandle.cpp	2012-02-20 18:05:02.000000000 +0300
@@ -727,7 +727,7 @@
 
 CqTiffFileHandle::CqTiffFileHandle(const boostfs::path& fileName, const char* openMode)
 	: m_fileName(fileName),
-	m_tiffPtr(TIFFOpen(fileName.file_string().c_str(), openMode), safeTiffClose),
+	m_tiffPtr(TIFFOpen(fileName.string().c_str(), openMode), safeTiffClose),
 	m_isInputFile(openMode[0] == 'r'),
 	m_currDir(0)
 {
