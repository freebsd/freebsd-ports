--- QtAwesome.cpp	2015-03-19 20:21:38 UTC
+++ QtAwesome.cpp	2015-04-20 15:57:35 -0400
@@ -155,6 +155,7 @@ void QtAwesome::init(const QString& font
 /// To initialize QtAwesome with font-awesome you need to call this method
 bool QtAwesome::initFontAwesome( )
 {
+#if 0
     static int fontAwesomeFontId = -1;
 
     // only load font-awesome once
@@ -189,6 +190,7 @@ bool QtAwesome::initFontAwesome( )
         fontAwesomeFontId = -1; // restore the font-awesome id
         return false;
     }
+#endif
 
     // intialize the map
     QHash<QString, int>& m = namedCodepoints_;
