--- lgc-pg/misc.h.orig	2020-10-31 10:02:28 UTC
+++ lgc-pg/misc.h
@@ -158,8 +158,13 @@ void copy_surf_mirrored( SDL_Surface *source, SDL_Rect
 void copy_surf_mirrored( SDL_Surface *source, SDL_Rect *srect, SDL_Surface *dest, SDL_Rect *drect );
 
 /** Macro wrapper to read data from file with (very) simple error handling.
- * Only to be used as standalone command, not in conditions. */
+ * Only to be used as standalone command, not in conditions. PG data is little
+ * endian and mostly read into (zeroed) ints, so if less bytes than the size of
+ * the destination are read, move them to its low end on big endian hosts. */
 #define _fread(ptr,size,nmemb,stream) \
-	do { int _freadretval = fread(ptr,size,nmemb,stream); if (_freadretval != nmemb && !feof(stream)) fprintf(stderr, "%s: %d: _fread error\n",__FILE__,__LINE__);} while (0)
+	do { int _freadretval = fread(ptr,size,nmemb,stream); if (_freadretval != nmemb && !feof(stream)) fprintf(stderr, "%s: %d: _fread error\n",__FILE__,__LINE__); \
+	if (SDL_BYTEORDER == SDL_BIG_ENDIAN && (size)*(nmemb) < sizeof(*(ptr))) { \
+		memmove((char*)(ptr) + sizeof(*(ptr)) - (size)*(nmemb), ptr, (size)*(nmemb)); \
+		memset(ptr, 0, sizeof(*(ptr)) - (size)*(nmemb)); } } while (0)
 
 #endif
