--- sdlscreen.c.orig	2023-04-11 14:41:38 UTC
+++ sdlscreen.c
@@ -373,17 +373,11 @@ byte * Surface_to_bytefield(SDL_Surface *source, byte
   byte *src;
   byte *dest_ptr;
   int y;
-  int remainder;

   // Support seulement des images 256 couleurs
   if (source->format->BytesPerPixel != 1)
     return NULL;

-  if (source->w & 3)
-    remainder=4-(source->w&3);
-  else
-    remainder=0;
-
   if (dest==NULL)
     dest=(byte *)malloc(source->w*source->h);

@@ -393,7 +387,7 @@ byte * Surface_to_bytefield(SDL_Surface *source, byte
   {
     memcpy(dest_ptr, src,source->w);
     dest_ptr += source->w;
-    src += source->w + remainder;
+    src += source->pitch;
   }
   return dest;

