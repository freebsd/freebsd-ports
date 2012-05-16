--- libs/tex/io/exrinputfile.cpp.orig	2012-02-20 18:09:25.000000000 +0300
+++ libs/tex/io/exrinputfile.cpp	2012-02-20 18:09:41.000000000 +0300
@@ -163,7 +163,7 @@
 {
 	try
 	{
-		m_exrFile.reset(new Imf::InputFile(fileName.file_string().c_str()));
+		m_exrFile.reset(new Imf::InputFile(fileName.string().c_str()));
 	}
 	catch(Iex::BaseExc &e)
 	{
