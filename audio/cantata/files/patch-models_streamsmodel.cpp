--- models/streamsmodel.cpp.orig	2025-12-02 21:34:28 UTC
+++ models/streamsmodel.cpp
@@ -1300,8 +1300,9 @@ QList<StreamsModel::Item*> StreamsModel::parseIceCastR
 
 	if (isGZipped) {
 		compressor = new KCompressionDevice(dev, false, KCompressionDevice::GZip);
-		compressor->open(QIODevice::ReadOnly);
-		readDev = compressor;
+		if (compressor->open(QIODevice::ReadOnly)) {
+			readDev = compressor;
+		}
 	}
 	QXmlStreamReader doc(readDev);
 
