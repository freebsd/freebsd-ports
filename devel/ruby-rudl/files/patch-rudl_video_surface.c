--- rudl_video_surface.c.orig	Sun Oct 19 20:26:13 2003
+++ rudl_video_surface.c	Mon Apr 19 04:14:08 2004
@@ -58,7 +58,7 @@
 	return surface;
 }
 
-__inline__ void setMasksFromBPP(Uint32 bpp, boolean alphaWanted, Uint32* Rmask, Uint32* Gmask, Uint32* Bmask, Uint32* Amask)
+__inline__ void setMasksFromBPP(Uint32 bpp, int alphaWanted, Uint32* Rmask, Uint32* Gmask, Uint32* Bmask, Uint32* Amask)
 {
 	*Amask = 0;
 	if(alphaWanted && (bpp==32||bpp==16)){
