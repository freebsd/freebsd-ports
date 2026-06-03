--- cryptoplugin/src/files.cpp.orig	2025-09-03 18:55:57 UTC
+++ cryptoplugin/src/files.cpp
@@ -118,7 +118,7 @@ size_t FileStore::CopyRangeTo2(BufferedTransformation 
 	if (begin == 0 && end == 1)
 	{
 		int result = m_stream->peek();
-		if (result == std::char_traits<char>::eof())
+		if (result == std::vector<char>::eof())
 			return 0;
 		else
 		{
