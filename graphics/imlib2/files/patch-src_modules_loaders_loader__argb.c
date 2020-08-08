--- src/modules/loaders/loader_argb.c.orig	2020-08-08 14:27:16 UTC
+++ src/modules/loaders/loader_argb.c
@@ -7,6 +7,9 @@ load2(ImlibImage * im, int load_data)
    int                 w = 0, h = 0, alpha = 0;
    DATA32             *ptr;
    int                 y;
+#ifdef WORDS_BIGENDIAN
+   int                 l;
+#endif
 
    rc = LOAD_FAIL;
 
