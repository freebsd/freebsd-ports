--- ./TvVideoFilter.h.orig	Sat Apr  7 19:48:42 2007
+++ ./TvVideoFilter.h	Sat Apr  7 19:49:43 2007
@@ -19,7 +19,7 @@
 
 class TvVideoFilter : public VideoFilter {
 public:    
-    TvVideoFilter::TvVideoFilter();
+    TvVideoFilter();
     int getFinalOutputWidth();
     int getFinalOutputHeight();
     void Filter(SDL_Surface *s, SDL_Surface *d);
