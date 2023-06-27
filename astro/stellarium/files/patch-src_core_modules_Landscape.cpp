--- src/core/modules/Landscape.cpp.orig	2023-03-12 18:30:15 UTC
+++ src/core/modules/Landscape.cpp
@@ -721,7 +721,10 @@ void LandscapeOldStyle::load(const QSettings& landscap
 
 void LandscapeOldStyle::draw(StelCore* core, bool onlyPolygon)
 {
-	if(!StelOpenGL::globalShaderPrefix(StelOpenGL::FRAGMENT_SHADER).contains("textureGrad_SUPPORTED"))
+	// Resort to drawLowGL() on FreeBSD until these bugs are fixed:
+	// https://github.com/Stellarium/stellarium/issues/3145
+	// https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=271995
+	if(true)
 	{
 		drawLowGL(core, onlyPolygon);
 		return;
