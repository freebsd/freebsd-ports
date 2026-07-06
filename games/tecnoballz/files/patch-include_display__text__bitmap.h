--- include/display_text_bitmap.h.orig	2026-06-25 07:43:41 UTC
+++ include/display_text_bitmap.h
@@ -38,7 +38,6 @@ class display_text_bitmap:public virtual tecnoballz (p
 class display_text_bitmap:public virtual tecnoballz
 {
 protected:
-  static const Uint32 CHAR_WIDTH = 8;
   static char ascii2code[128];
   Sint32 off_desti1;            // modulo destination affichage ecran
   Sint32 off_source;            // modulo source page graphique
