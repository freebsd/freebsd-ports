--- src/external/flash/flash.h.orig	2007-07-01 16:43:08.000000000 +0000
+++ src/external/flash/flash.h	2011-08-10 01:34:57.000000000 +0000
@@ -33,9 +33,9 @@
 {	
 	public:
 		static void exportFlash(Object* object, int startFrame, int endFrame, QMatrix view, QSize exportSize, QString filePath, int fps, int compression);
-		static void convertToSWFSprite( BitmapImage* image, Object* object, QMatrix view, SWFSprite* sprite );
-		static void convertToSWFSprite( VectorImage* vectorImage, Object* object, QMatrix view, SWFSprite* sprite );
-		static void addShape( SWFSprite* sprite, QPainterPath path, QColor fillColour, QColor borderColour, qreal width, bool fill );
+		static void convertToSWFMovieClip( BitmapImage* image, Object* object, QMatrix view, SWFMovieClip* sprite );
+		static void convertToSWFMovieClip( VectorImage* vectorImage, Object* object, QMatrix view, SWFMovieClip* sprite );
+		static void addShape( SWFMovieClip* sprite, QPainterPath path, QColor fillColour, QColor borderColour, qreal width, bool fill );
 };
 
 #endif
