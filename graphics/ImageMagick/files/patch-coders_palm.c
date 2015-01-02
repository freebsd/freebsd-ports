--- coders/palm.c	2014-12-25 19:05:34.000000000 +0100
+++ coders/palm.c	2014-12-31 09:38:35.499493971 +0100
@@ -510,7 +510,7 @@
       {
         IndexPacket index=ConstrainColormapIndex(image,(mask-transparentIndex));
         if (bits_per_pixel != 16)
-          SetMagickPixelPacket(image,image->colormap+index,
+          SetMagickPixelPacket(image,image->colormap+(ssize_t) index,
             (const IndexPacket *) NULL,&transpix);
         (void) TransparentPaintImage(image,&transpix,(Quantum)
           TransparentOpacity,MagickFalse);
