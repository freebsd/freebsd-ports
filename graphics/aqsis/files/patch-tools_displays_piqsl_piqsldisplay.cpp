--- tools/displays/piqsl/piqsldisplay.cpp.orig	2012-08-24 12:26:50 UTC
+++ tools/displays/piqsl/piqsldisplay.cpp
@@ -450,8 +450,8 @@ extern "C" PtDspyError DspyImageData(PtD
 
 	TiXmlElement* bucketDataXML = new TiXmlElement("BucketData");
 	std::stringstream base64Data;
-	std::copy(	base64_text(BOOST_MAKE_PFTO_WRAPPER(data)), 
-				base64_text(BOOST_MAKE_PFTO_WRAPPER(data + bufferlength)), 
+	std::copy(	base64_text(data), 
+				base64_text(data + bufferlength), 
 				std::ostream_iterator<char>(base64Data));
 	TiXmlText* dataTextXML = new TiXmlText(base64Data.str());
 	dataTextXML->SetCDATA(true);
