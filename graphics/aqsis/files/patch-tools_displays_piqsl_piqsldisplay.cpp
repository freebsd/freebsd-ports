tools/displays/piqsl/piqsldisplay.cpp:400:35: error: non-constant-expression cannot be narrowed from type 'TqInt' (aka 'int') to 'unsigned int' in initializer list [-Wc++11-narrowing]
                                        PtDspyDevFormat fmt = {name, typeID};
                                                                     ^~~~~~
tools/displays/piqsl/piqsldisplay.cpp:400:35: note: insert an explicit cast to silence this issue
                                        PtDspyDevFormat fmt = {name, typeID};
                                                                     ^~~~~~
                                                                     static_cast<unsigned int>( )

--- tools/displays/piqsl/piqsldisplay.cpp.orig	2012-08-24 12:26:50 UTC
+++ tools/displays/piqsl/piqsldisplay.cpp
@@ -397,7 +397,7 @@ extern "C" PtDspyError DspyImageOpen(PtDspyImageHandle
 					TqInt typeID = g_mapNameToType[typeName];
 					char* name = new char[strlen(formatName)+1];
 					strcpy(name, formatName);
-					PtDspyDevFormat fmt = {name, typeID};
+					PtDspyDevFormat fmt = {name, static_cast<unsigned>(typeID)};
 					outFormat.push_back(fmt);
 					formatNode = formatNode->NextSiblingElement("Format");
 					iformat++;
@@ -450,8 +450,8 @@ extern "C" PtDspyError DspyImageData(PtDspyImageHandle
 
 	TiXmlElement* bucketDataXML = new TiXmlElement("BucketData");
 	std::stringstream base64Data;
-	std::copy(	base64_text(BOOST_MAKE_PFTO_WRAPPER(data)), 
-				base64_text(BOOST_MAKE_PFTO_WRAPPER(data + bufferlength)), 
+	std::copy(	base64_text(data), 
+				base64_text(data + bufferlength), 
 				std::ostream_iterator<char>(base64Data));
 	TiXmlText* dataTextXML = new TiXmlText(base64Data.str());
 	dataTextXML->SetCDATA(true);
