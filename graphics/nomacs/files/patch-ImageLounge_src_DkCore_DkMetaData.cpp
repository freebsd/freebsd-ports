--- ImageLounge/src/DkCore/DkMetaData.cpp.orig	2020-07-17 07:05:29 UTC
+++ ImageLounge/src/DkCore/DkMetaData.cpp
@@ -73,8 +73,8 @@ void DkMetaDataT::readMetaData(const QString& filePath
 			mExifImg = Exiv2::ImageFactory::open(strFilePath);
 		}
 		else {
-			Exiv2::BasicIo::AutoPtr exifBuffer(new Exiv2::MemIo((const byte*)ba->constData(), ba->size()));
-			mExifImg = Exiv2::ImageFactory::open(exifBuffer);
+			Exiv2::BasicIo::UniquePtr exifBuffer(new Exiv2::MemIo((const byte*)ba->constData(), ba->size()));
+			mExifImg = Exiv2::ImageFactory::open(std::move(exifBuffer));
 		}
 	} 
 	catch (...) {
@@ -156,13 +156,13 @@ bool DkMetaDataT::saveMetaData(QSharedPointer<QByteArr
 	Exiv2::XmpData &xmpData = mExifImg->xmpData();
 	Exiv2::IptcData &iptcData = mExifImg->iptcData();
 
-	Exiv2::Image::AutoPtr exifImgN;
-	Exiv2::MemIo::AutoPtr exifMem;
+	Exiv2::Image::UniquePtr exifImgN;
+	Exiv2::MemIo::UniquePtr exifMem;
 
 	try {
 
-		exifMem = Exiv2::MemIo::AutoPtr(new Exiv2::MemIo((byte*)ba->data(), ba->size()));
-		exifImgN = Exiv2::ImageFactory::open(exifMem);
+		exifMem = Exiv2::MemIo::UniquePtr(new Exiv2::MemIo((byte*)ba->data(), ba->size()));
+		exifImgN = Exiv2::ImageFactory::open(std::move(exifMem));
 	} 
 	catch (...) {
 
@@ -186,8 +186,8 @@ bool DkMetaDataT::saveMetaData(QSharedPointer<QByteArr
 
 	// now get the data again
 	Exiv2::DataBuf exifBuf = exifImgN->io().read((long)exifImgN->io().size());
-	if (exifBuf.pData_) {
-		QSharedPointer<QByteArray> tmp = QSharedPointer<QByteArray>(new QByteArray((const char*)exifBuf.pData_, exifBuf.size_));
+	if (exifBuf.c_data()) {
+		QSharedPointer<QByteArray> tmp = QSharedPointer<QByteArray>(new QByteArray((const char*)exifBuf.c_data(), exifBuf.size()));
 
 		if (tmp->size() > qRound(ba->size()*0.5f))
 			ba = tmp;
@@ -197,7 +197,7 @@ bool DkMetaDataT::saveMetaData(QSharedPointer<QByteArr
 	else
 		return false;
 
-	mExifImg = exifImgN;
+	mExifImg = std::move(exifImgN);
 	mExifState = loaded;
 
 	return true;
@@ -250,7 +250,7 @@ int DkMetaDataT::getOrientationDegree() const {
 
 			if (pos != exifData.end() && pos->count() != 0) {
 			
-				Exiv2::Value::AutoPtr v = pos->getValue();
+				Exiv2::Value::UniquePtr v = pos->getValue();
 				orientation = (int)pos->toFloat();
 
 				switch (orientation) {
@@ -315,7 +315,7 @@ int DkMetaDataT::getRating() const {
 		Exiv2::ExifData::iterator pos = exifData.findKey(key);
 
 		if (pos != exifData.end() && pos->count() != 0) {
-			Exiv2::Value::AutoPtr v = pos->getValue();
+			Exiv2::Value::UniquePtr v = pos->getValue();
 			exifRating = v->toFloat();
 		}
 	}
@@ -327,7 +327,7 @@ int DkMetaDataT::getRating() const {
 
 		//xmp Rating tag
 		if (pos != xmpData.end() && pos->count() != 0) {
-			Exiv2::Value::AutoPtr v = pos->getValue();
+			Exiv2::Value::UniquePtr v = pos->getValue();
 			xmpRating = v->toFloat();
 		}
 
@@ -336,7 +336,7 @@ int DkMetaDataT::getRating() const {
 			key = Exiv2::XmpKey("Xmp.MicrosoftPhoto.Rating");
 			pos = xmpData.findKey(key);
 			if (pos != xmpData.end() && pos->count() != 0) {
-				Exiv2::Value::AutoPtr v = pos->getValue();
+				Exiv2::Value::UniquePtr v = pos->getValue();
 				xmpRating = v->toFloat();
 			}
 		}
@@ -399,7 +399,7 @@ QString DkMetaDataT::getNativeExifValue(const QString&
 			if (pos->count () < 2000) {	// diem: this is about performance - adobe obviously embeds whole images into tiff exiv data 
 
 				//qDebug() << "pos count: " << pos->count();
-				//Exiv2::Value::AutoPtr v = pos->getValue();
+				//Exiv2::Value::UniquePtr v = pos->getValue();
 				info = exiv2ToQString(pos->toString());
 
 			}
@@ -436,7 +436,7 @@ QString DkMetaDataT::getXmpValue(const QString& key) c
 		}
 
 		if (pos != xmpData.end() && pos->count() != 0) {
-			Exiv2::Value::AutoPtr v = pos->getValue();
+			Exiv2::Value::UniquePtr v = pos->getValue();
 			info = exiv2ToQString(pos->toString());
 		}
 	}
@@ -478,7 +478,7 @@ QString DkMetaDataT::getExifValue(const QString& key) 
 		}
 
 		if (pos != exifData.end() && pos->count() != 0) {
-			//Exiv2::Value::AutoPtr v = pos->getValue();
+			//Exiv2::Value::UniquePtr v = pos->getValue();
 			info = exiv2ToQString(pos->toString());
 		}
 	}
@@ -508,7 +508,7 @@ QString DkMetaDataT::getIptcValue(const QString& key) 
 		}
 
 		if (pos != iptcData.end() && pos->count() != 0) {
-			Exiv2::Value::AutoPtr v = pos->getValue();
+			Exiv2::Value::UniquePtr v = pos->getValue();
 			info = exiv2ToQString(pos->toString());
 		}
 	}
@@ -654,7 +654,7 @@ QImage DkMetaDataT::getThumbnail() const {
 		Exiv2::ExifThumb thumb(exifData);
 		Exiv2::DataBuf buffer = thumb.copy();
 
-		QByteArray ba = QByteArray((char*)buffer.pData_, buffer.size_);
+		QByteArray ba = QByteArray((char*)buffer.c_data(), buffer.size());
 		qThumb.loadFromData(ba);
 	}
 	catch (...) {
@@ -931,8 +931,8 @@ void DkMetaDataT::setThumbnail(QImage thumb) {
 
 		try {
 			// whipe all exif data of the thumbnail
-			Exiv2::MemIo::AutoPtr exifBufferThumb(new Exiv2::MemIo((const byte*)ba.constData(), ba.size()));
-			Exiv2::Image::AutoPtr exifImgThumb = Exiv2::ImageFactory::open(exifBufferThumb);
+			Exiv2::MemIo::UniquePtr exifBufferThumb(new Exiv2::MemIo((const byte*)ba.constData(), ba.size()));
+			Exiv2::Image::UniquePtr exifImgThumb = Exiv2::ImageFactory::open(std::move(exifBufferThumb));
 
 			if (exifImgThumb.get() != 0 && exifImgThumb->good())
 				exifImgThumb->clearExifData();
@@ -1045,11 +1045,11 @@ void DkMetaDataT::setOrientation(int o) {
 		pos = exifData.findKey(key);
 	}
 
-	Exiv2::Value::AutoPtr v = pos->getValue();
+	Exiv2::Value::UniquePtr v = pos->getValue();
 	Exiv2::UShortValue* prv = dynamic_cast<Exiv2::UShortValue*>(v.release());
 	if (!prv) return;
 
-	Exiv2::UShortValue::AutoPtr rv = Exiv2::UShortValue::AutoPtr(prv);
+	Exiv2::UShortValue::UniquePtr rv = Exiv2::UShortValue::UniquePtr(prv);
 	if (rv->value_.empty())	return;
 
 	orientation = (int) rv->value_[0];
@@ -1110,7 +1110,7 @@ void DkMetaDataT::setRating(int r) {
 		exifData["Exif.Image.Rating"] = uint16_t(r);
 		exifData["Exif.Image.RatingPercent"] = uint16_t(r);
 
-		Exiv2::Value::AutoPtr v = Exiv2::Value::create(Exiv2::xmpText);
+		Exiv2::Value::UniquePtr v = Exiv2::Value::create(Exiv2::xmpText);
 		v->read(sRating);
 		xmpData.add(Exiv2::XmpKey("Xmp.xmp.Rating"), v.get());
 		v->read(sRatingPercent);
@@ -1354,9 +1354,9 @@ DkRotatingRect DkMetaDataT::getXMPRect(const QSize& si
 	return DkRotatingRect(rr);
 }
 
-Exiv2::Image::AutoPtr DkMetaDataT::loadSidecar(const QString& filePath) const {
+Exiv2::Image::UniquePtr DkMetaDataT::loadSidecar(const QString& filePath) const {
 
-	Exiv2::Image::AutoPtr xmpImg;
+	Exiv2::Image::UniquePtr xmpImg;
 
 	//TODO: check if the file type supports xmp
 
@@ -1409,7 +1409,7 @@ bool DkMetaDataT::setXMPValue(Exiv2::XmpData& xmpData,
 				setXMPValueSuccessful = true;
 		}
 		else {
-			Exiv2::Value::AutoPtr v = Exiv2::Value::create(Exiv2::xmpText);
+			Exiv2::Value::UniquePtr v = Exiv2::Value::create(Exiv2::xmpText);
 			if (!v->read(xmpValue.toStdString())) {
 				if (!xmpData.add(Exiv2::XmpKey(key), v.get()))
 					setXMPValueSuccessful = true;
