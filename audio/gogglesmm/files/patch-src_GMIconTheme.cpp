Fix build with FOX 1.7.80

--- src/GMIconTheme.cpp.orig	2022-10-28 03:25:41 UTC
+++ src/GMIconTheme.cpp
@@ -569,7 +569,11 @@ void GMIconTheme::loadLarge(FXIconPtr & icon,const FXc
     loadIcon(icon,FXString::null,largesize,value,blendcolor);
   }
 
+#if FOXVERSION >= FXVERSION(1, 7, 80)
+void GMIconTheme::loadResource(FXIconPtr & icon,const FXuchar * data,const FXColor blendcolor,const char * type) {
+#else
 void GMIconTheme::loadResource(FXIconPtr & icon,const void * data,const FXColor blendcolor,const char * type) {
+#endif
   FXIconSource source;
   FXIcon * newicon = source.loadIconData(app,data,type);
   FXASSERT(newicon);
