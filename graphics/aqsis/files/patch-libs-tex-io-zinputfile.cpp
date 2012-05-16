--- libs/tex/io/zinputfile.cpp.orig	2012-02-20 18:08:03.000000000 +0300
+++ libs/tex/io/zinputfile.cpp	2012-02-20 18:08:19.000000000 +0300
@@ -41,7 +41,7 @@
 CqZInputFile::CqZInputFile(const boostfs::path& fileName)
 	: m_header(),
 	m_fileName(fileName),
-	m_fileStream(fileName.file_string().c_str(), std::ios::in | std::ios::binary),
+	m_fileStream(fileName.string().c_str(), std::ios::in | std::ios::binary),
 	m_dataBegin(0)
 {
 	if(!m_fileStream.is_open())
