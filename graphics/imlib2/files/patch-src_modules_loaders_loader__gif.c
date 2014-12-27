--- src/modules/loaders/loader_gif.c.orig	2013-12-21 10:16:10 UTC
+++ src/modules/loaders/loader_gif.c
@@ -36,7 +36,11 @@ load(ImlibImage * im, ImlibProgressFunct
 #endif
    if (fd < 0)
       return 0;
+#if GIFLIB_MAJOR >= 5
+   gif = DGifOpenFileHandle(fd, NULL);
+#else
    gif = DGifOpenFileHandle(fd);
+#endif
    if (!gif)
      {
         close(fd);
