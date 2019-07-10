--- src/DkCore/DkMetaData.cpp.orig	2019-07-07 07:58:56 UTC
+++ src/DkCore/DkMetaData.cpp
@@ -40,6 +40,7 @@
 #include <QVector2D>
 #include <QApplication>
 #pragma warning(pop)		// no warnings from includes - end
+#include <iostream>
 
 namespace nmc {
 
@@ -1262,7 +1263,7 @@ void DkMetaDataT::printMetaData() const {
 
 	std::string xmpPacket;
 	if (0 != Exiv2::XmpParser::encode(xmpPacket, xmpData)) {
-		throw Exiv2::Error(1, "Failed to serialize XMP data");
+		throw Exiv2::Error(Exiv2::ErrorCode::kerErrorMessage, "Failed to serialize XMP data");
 	}
 	std::cout << xmpPacket << "\n";
 }
