# Origin: https://github.com/naev/naev/commit/9fd2a7dcb3690bc1befe7f9a05d02e204dcfe8a1
# Subject: Avoid regenerating the land tabs over top of themselves

--- src/land_outfits.c.orig	2015-03-05 22:11:11 UTC
+++ src/land_outfits.c
@@ -95,6 +95,9 @@ void outfits_open( unsigned int wid )
 {
    int w, h, iw, ih, bw, bh, off;
 
+   /* Mark as generated. */
+   land_tabGenerate(LAND_WINDOW_OUTFITS);
+
    /* Get dimensions. */
    outfits_getSize( wid, &w, &h, &iw, &ih, &bw, &bh );
 
