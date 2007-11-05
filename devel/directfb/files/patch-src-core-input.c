--- src/core/input.c.orig	2002-12-29 01:17:06.000000000 +0100
+++ src/core/input.c	2007-11-02 12:17:48.000000000 +0100
@@ -1312,7 +1312,7 @@
 
           write( fd, buf24, surface->width * 3 );
 
-          ((__u8*)data) += pitch;
+          data = (__u8*)data + pitch;
      }
 
      dfb_surface_unlock( surface, (surface->caps & DSCAPS_FLIPPING) );
