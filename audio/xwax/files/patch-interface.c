--- interface.c.orig	2023-05-12 17:27:59 UTC
+++ interface.c
@@ -414,11 +414,12 @@ static int do_draw_text(SDL_Surface *sf, const struct 
         src.h = 0;
 
     } else {
+        char *in = NULL;
         if (!locale) {
             rendered = TTF_RenderText_Shaded(font, buf, fg, bg);
         } else {
             char ubuf[256], /* fixed buffer is reasonable for rendering */
-                *in, *out;
+                *out;
             size_t len, fill;
 
             out = ubuf;
@@ -427,7 +428,7 @@ static int do_draw_text(SDL_Surface *sf, const struct 
             if (iconv(utf, NULL, NULL, &out, &fill) == -1)
                 abort();
 
-            in = strdupa(buf);
+            in = strdup(buf);
             len = strlen(in);
 
             (void)iconv(utf, &in, &len, &out, &fill);
@@ -446,6 +447,8 @@ static int do_draw_text(SDL_Surface *sf, const struct 
 
         SDL_BlitSurface(rendered, &src, sf, &dst);
         SDL_FreeSurface(rendered);
+
+        //free(in); // this crashes with free() enabled for unknown reason, it's better to just lose the memory here
     }
 
     /* Complete the remaining space with a blank rectangle */
