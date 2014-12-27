--- jdk/src/share/native/sun/awt/splashscreen/splashscreen_gif.c.orig	2014-03-04 02:59:38 UTC
+++ jdk/src/share/native/sun/awt/splashscreen/splashscreen_gif.c
@@ -318,7 +318,11 @@ SplashDecodeGif(Splash * splash, GifFile
 int
 SplashDecodeGifStream(Splash * splash, SplashStream * stream)
 {
+#if GIFLIB_MAJOR >= 5
+    GifFileType *gif = DGifOpen((void *) stream, SplashStreamGifInputFunc, NULL);
+#else
     GifFileType *gif = DGifOpen((void *) stream, SplashStreamGifInputFunc);
+#endif
 
     if (!gif)
         return 0;
