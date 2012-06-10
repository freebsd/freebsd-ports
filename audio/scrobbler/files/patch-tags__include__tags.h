--- ./tags/include/tags.h.orig	2012-05-19 17:35:23.000000000 -0400
+++ ./tags/include/tags.h	2012-05-19 17:36:12.000000000 -0400
@@ -31,7 +31,6 @@
 #include "vorbis.h"
 #include "itunes.h"
 #include "ape.h"
-#include "cdaudio.h"
 
 extern const char *genre_list[148];
 
@@ -59,7 +58,6 @@
 			has_oggflac,
 			has_speex,
 			has_itunes,
-			has_cdaudio,
 			prefer_ape;
 	wma_t		*wma;
 	id3v1_t		*id3v1;
@@ -70,7 +68,6 @@
 			*oggflac,
 			*speex;
 	itunes_t	*itunes;
-	cdaudio_t	*cdaudio;
 } metatag_t;
 
 void get_tag_data(metatag_t *, char *, int);
