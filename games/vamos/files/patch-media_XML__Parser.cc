--- media/XML_Parser.cc.orig	2014-02-03 01:08:19 UTC
+++ media/XML_Parser.cc
@@ -391,7 +391,7 @@ XML_Parser::read (std::string file)
 {
   m_file = file;
   mp_stream = new std::ifstream (file.c_str ());
-  if ((mp_stream == 0) || (*mp_stream == 0))
+  if (!mp_stream || !*mp_stream)
 	{
 	  throw No_XML_File (m_file);
 	}
