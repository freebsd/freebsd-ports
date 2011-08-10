--- src/external/flash/flash.cpp.orig	2011-08-10 01:23:59.000000000 +0000
+++ src/external/flash/flash.cpp	2011-08-10 01:39:01.000000000 +0000
@@ -34,7 +34,7 @@
 	movie->setRate(fps); // 12 frames per seconds
 	
   //SWFShape *shape = new SWFShape();
-	SWFSprite *objectSprite = new SWFSprite();
+	SWFMovieClip *objectSprite = new SWFMovieClip();
 	
 	for(int i=0; i < object->getLayerCount(); i++) {
 		Layer* layer = object->getLayer(i);
@@ -42,14 +42,14 @@
 			// paints the bitmap images
 			if(layer->type == Layer::BITMAP) {
 				LayerBitmap* layerBitmap = (LayerBitmap*)layer;
-				SWFSprite *layerSprite = new SWFSprite();
+				SWFMovieClip *layerSprite = new SWFMovieClip();
 				SWFDisplayItem *previousItem = NULL;
 				for(int frameNumber = startFrame; frameNumber <= endFrame; frameNumber++) {
 					BitmapImage* bitmapImage = layerBitmap->getBitmapImageAtFrame(frameNumber);
 					if(bitmapImage != NULL) {
 						if(previousItem != NULL) layerSprite->remove( previousItem );
-						SWFSprite *imageSprite = new SWFSprite();
-						convertToSWFSprite( bitmapImage, object, view, imageSprite);
+						SWFMovieClip *imageSprite = new SWFMovieClip();
+						convertToSWFMovieClip( bitmapImage, object, view, imageSprite);
 						previousItem = layerSprite->add( imageSprite );
 					}
 					layerSprite->nextFrame();
@@ -61,14 +61,14 @@
 			// paints the vector images
 			if(layer->type == Layer::VECTOR) {
 				LayerVector* layerVector = (LayerVector*)layer;
-				SWFSprite *layerSprite = new SWFSprite();
+				SWFMovieClip *layerSprite = new SWFMovieClip();
 				SWFDisplayItem *previousItem = NULL;
 				for(int frameNumber = startFrame; frameNumber <= endFrame; frameNumber++) {
 					VectorImage* vectorImage = layerVector->getVectorImageAtFrame(frameNumber);
 					if(vectorImage != NULL) {
 						if(previousItem != NULL) layerSprite->remove( previousItem );
-						SWFSprite *sprite = new SWFSprite();
-						convertToSWFSprite( vectorImage, object, view, sprite);
+						SWFMovieClip *sprite = new SWFMovieClip();
+						convertToSWFMovieClip( vectorImage, object, view, sprite);
 						previousItem = layerSprite->add( sprite );
 					}
 					layerSprite->nextFrame();
@@ -98,8 +98,8 @@
 }
 
 
-void Flash::convertToSWFSprite( BitmapImage* bitmapImage, Object* object, QMatrix view, SWFSprite* sprite ) {
-	QString tempPath = QDir::tempPath()+"penciltemp.png";
+void Flash::convertToSWFMovieClip( BitmapImage* bitmapImage, Object* object, QMatrix view, SWFMovieClip* sprite ) {
+	QString tempPath = QDir::tempPath()+"/penciltemp.png";
 	QByteArray tempPath2( tempPath.toLatin1());
 	bitmapImage->image->save( tempPath , "PNG");
 	SWFShape *shape = new SWFShape();
@@ -118,7 +118,7 @@
 }
 
 
-void Flash::convertToSWFSprite( VectorImage* vectorImage, Object* object, QMatrix view, SWFSprite* sprite ) {
+void Flash::convertToSWFMovieClip( VectorImage* vectorImage, Object* object, QMatrix view, SWFMovieClip* sprite ) {
 	
 	// add filled areas
 	for(int i=0; i< vectorImage->area.size(); i++) {
@@ -146,7 +146,7 @@
 
 
 
-void Flash::addShape( SWFSprite* sprite, QPainterPath path, QColor fillColour, QColor borderColour, qreal width, bool fill ) {
+void Flash::addShape( SWFMovieClip* sprite, QPainterPath path, QColor fillColour, QColor borderColour, qreal width, bool fill ) {
 	SWFShape* shape = new SWFShape();
 	//float widthf = static_cast< float >(width);
 	if(width == 0.0) {
