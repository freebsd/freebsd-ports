--- examples/audio_out.c.orig	2016-09-13 10:20:20 UTC
+++ examples/audio_out.c
@@ -33,9 +33,9 @@
 #define MAKE_MAGIC(a,b,c,d,e,f,g,h)		\
 			((a) + ((b) << 1) + ((c) << 2) + ((d) << 3) + ((e) << 4) + ((f) << 5) + ((g) << 6) + ((h) << 7))
 
-typedef	struct AUDIO_OUT_s
+struct AUDIO_OUT_s
 {	int magic ;
-} AUDIO_OUT ;
+};
 
 
 /*------------------------------------------------------------------------------
