--- src/modules/loaders/loader_argb.c.orig	Wed Nov  8 19:39:37 2006
+++ src/modules/loaders/loader_argb.c	Wed Nov  8 19:41:38 2006
@@ -23,7 +23,7 @@
 load(ImlibImage * im, ImlibProgressFunction progress,
      char progress_granularity, char immediate_load)
 {
-   int                 w, h, alpha;
+   int                 w = 0, h = 0, alpha = 0;
    FILE               *f;
 
    if (im->data)
@@ -36,13 +36,16 @@
    {
       char                buf[256], buf2[256];
 
+      bzero(buf, sizeof(buf));
+      bzero(buf2, sizeof(buf2));
+
       if (!fgets(buf, 255, f))
         {
            fclose(f);
            return 0;
         }
       sscanf(buf, "%s %i %i %i", buf2, &w, &h, &alpha);
-      if (strcmp(buf2, "ARGB"))
+      if (strcmp(buf2, "ARGB") || w < 1 || h < 1 || w > 16383 || h > 16383)
         {
            fclose(f);
            return 0;
