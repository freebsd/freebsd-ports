--- src/DkCore/DkMetaData.cpp.orig	2019-03-08 21:53:21 UTC
+++ src/DkCore/DkMetaData.cpp
@@ -1262,7 +1262,7 @@ void DkMetaDataT::printMetaData() const {
 
 	std::string xmpPacket;
 	if (0 != Exiv2::XmpParser::encode(xmpPacket, xmpData)) {
-		throw Exiv2::Error(1, "Failed to serialize XMP data");
+		throw Exiv2::Error(Exiv2::ErrorCode::kerErrorMessage, "Failed to serialize XMP data");
 	}
 	std::cout << xmpPacket << "\n";
 }
