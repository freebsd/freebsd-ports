--- filter.h.orig	2025-10-04 23:10:13 UTC
+++ filter.h
@@ -511,8 +511,8 @@ typedef		void (*intFunc)( unsigned char *dst, 	unsigne
 // Interpolating functions for resampler
 
 typedef		void (*intFunc)( unsigned char *dst, 	unsigned char **rgb,
-							register double Dx, 
-							register double Dy,
+							double Dx, 
+							double Dy,
 							int color, int SamplesPerPixel);
 
 // Filter function type for anti aliasing Filter
@@ -747,8 +747,8 @@ PANO13_IMPEX int	getVRPanoOptions	( VRPanoOptions *v, 
 PANO13_IMPEX int 	readAdjust		( aPrefs *p,  fullPath* sfile, int insert, sPrefs *sP );
 PANO13_IMPEX void 	readControlPoints	(char* script, controlPoint *c );
 PANO13_IMPEX int	getVRPanoOptions	( VRPanoOptions *v, char *line );
-PANO13_IMPEX void 	nextWord			( register char* word, char** ch );
-PANO13_IMPEX void 	nextLine			( register char* line, char** ch );
+PANO13_IMPEX void 	nextWord			( char* word, char** ch );
+PANO13_IMPEX void 	nextLine			( char* line, char** ch );
 PANO13_IMPEX int 	numLines			( char* script, char first );
 
 PANO13_IMPEX char *panoParserFindOLine(char *script, int index);
