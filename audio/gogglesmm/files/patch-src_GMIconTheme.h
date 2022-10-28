Fix build with FOX 1.7.80

--- src/GMIconTheme.h.orig	2022-10-28 03:25:54 UTC
+++ src/GMIconTheme.h
@@ -47,7 +47,11 @@ class GMIconTheme { (protected)
   FXImage * loadImage(const FXString & filename);
 protected:
   void loadIcon(FXIconPtr & icon,const FXString &pathlist,FXint size,const char * value,const FXColor blend);
+#if FOXVERSION >= FXVERSION(1, 7, 80)
+  void loadResource(FXIconPtr & icon,const FXuchar * data,const FXColor blend,const char * type="png");
+#else
   void loadResource(FXIconPtr & icon,const void * data,const FXColor blend,const char * type="png");
+#endif
 protected:
   FXbool load_cache();
   void   save_cache();
