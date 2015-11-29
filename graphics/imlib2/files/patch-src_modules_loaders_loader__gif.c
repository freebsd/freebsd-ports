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
@@ -60,13 +64,21 @@ load(ImlibImage * im, ImlibProgressFunct
              h = gif->Image.Height;
              if (!IMAGE_DIMENSIONS_OK(w, h))
                {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+                  DGifCloseFile(gif, NULL);
+#else
                   DGifCloseFile(gif);
+#endif
                   return 0;
                }
              rows = malloc(h * sizeof(GifRowType *));
              if (!rows)
                {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+                  DGifCloseFile(gif, NULL);
+#else
                   DGifCloseFile(gif);
+#endif
                   return 0;
                }
              for (i = 0; i < h; i++)
@@ -78,7 +90,11 @@ load(ImlibImage * im, ImlibProgressFunct
                   rows[i] = malloc(w * sizeof(GifPixelType));
                   if (!rows[i])
                     {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+                       DGifCloseFile(gif, NULL);
+#else
                        DGifCloseFile(gif);
+#endif
                        for (i = 0; i < h; i++)
                          {
                             if (rows[i])
@@ -150,7 +166,11 @@ load(ImlibImage * im, ImlibProgressFunct
         im->data = (DATA32 *) malloc(sizeof(DATA32) * w * h);
         if (!im->data)
           {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+             DGifCloseFile(gif, NULL);
+#else
              DGifCloseFile(gif);
+#endif
              free(rows);
              return 0;
           }
@@ -181,7 +201,11 @@ load(ImlibImage * im, ImlibProgressFunct
                        last_per = (int)per;
                        if (!(progress(im, (int)per, 0, last_y, w, i)))
                          {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+                            DGifCloseFile(gif, NULL);
+#else
                             DGifCloseFile(gif);
+#endif
                             for (i = 0; i < h; i++)
                               {
                                  free(rows[i]);
@@ -198,7 +222,11 @@ load(ImlibImage * im, ImlibProgressFunct
      {
         progress(im, 100, 0, last_y, w, h);
      }
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+   DGifCloseFile(gif, NULL);
+#else
    DGifCloseFile(gif);
+#endif
    for (i = 0; i < h; i++)
      {
         free(rows[i]);
