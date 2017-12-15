Fixed security vulnerability in XCF image loader (thanks Yves!)
https://hg.libsdl.org/SDL_image/rev/318484db0705

--- IMG_xcf.c.orig	2012-01-21 01:51:33 UTC
+++ IMG_xcf.c
@@ -251,6 +251,7 @@ static Uint32 Swap32 (Uint32 v) {
 }
 
 static void xcf_read_property (SDL_RWops * src, xcf_prop * prop) {
+  Uint32 len;
   prop->id = SDL_ReadBE32 (src);
   prop->length = SDL_ReadBE32 (src);
 
@@ -274,7 +275,12 @@ static void xcf_read_property (SDL_RWops * src, xcf_pr
     break;
   case PROP_COMPRESSION:
   case PROP_COLOR:
-    SDL_RWread (src, &prop->data, prop->length, 1);
+    if (prop->length > sizeof(prop->data)) {
+        len = sizeof(prop->data);
+    } else {
+        len = prop->length;
+    }
+    SDL_RWread(src, &prop->data, len, 1);
     break;
   case PROP_VISIBLE:
     prop->data.visible = SDL_ReadBE32 (src);
