--- src/gtextutils/text_line_reader.cpp.orig	2018-03-29 13:31:53 UTC
+++ src/gtextutils/text_line_reader.cpp
@@ -44,6 +44,7 @@ bool TextLineReader::next_line() 
 	if (input_stream.eof())
 		return false;
 
-	return input_stream ;
+        // Fix based on the only code change since 0.7
+	return input_stream.good() ;
 }
 
