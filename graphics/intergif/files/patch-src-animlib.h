--- src/animlib.h.orig	Tue Oct  5 21:20:58 2004
+++ src/animlib.h	Sun Sep  4 16:38:34 2005
@@ -144,18 +144,18 @@
 
 BOOL Anim_ConvertSprite( const void *spritedata, size_t size,
                          anim_animfn animfn, anim_imagefn fn, void *handle );
-BOOL Anim_ConvertTCA( const void *tcadata, size_t size,
+BOOL Anim_ConvertTCA( const void *tcadata, unsigned int size,
                       anim_animfn animfn, anim_imagefn fn, void *handle );
 BOOL Anim_ConvertDraw( const void *drawdata, size_t size,
                        anim_animfn animfn, anim_imagefn fn, void *handle );
-BOOL Anim_ConvertGIF( const void *gifdata, size_t size,
+BOOL Anim_ConvertGIF( const void *gifdata, unsigned int size,
                       anim_animfn animfn, anim_imagefn fn, void *handle );
 
 /* Very high-level constructors (calling these will link in *all* the above
  * constructors)
  */
 
-BOOL Anim_ConvertData( const void *data, unsigned int size,
+BOOL Anim_ConvertData( const void *data, size_t size,
                     anim_animfn animfn, anim_imagefn fn, void *handle );
 BOOL Anim_ConvertFile( const char *filename,
                     anim_animfn animfn, anim_imagefn fn, void *handle );
