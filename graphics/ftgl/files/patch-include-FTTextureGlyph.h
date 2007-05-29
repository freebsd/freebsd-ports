--- include/FTTextureGlyph.h.orig	Tue May 29 21:42:13 2007
+++ include/FTTextureGlyph.h	Tue May 29 21:42:51 2007
@@ -52,7 +52,7 @@
          * Reset the currently active texture to zero to get into a known state before
          * drawing a string. This is to get round possible threading issues.
          */
-        static void FTTextureGlyph::ResetActiveTexture(){ activeTextureID = 0;}
+        static void ResetActiveTexture(){ activeTextureID = 0;}
         
     private:
         /**
