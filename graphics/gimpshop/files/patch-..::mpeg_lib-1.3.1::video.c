--- ../mpeg_lib-1.3.1/video.c.orig	Sat Jul 24 13:00:51 1999
+++ ../mpeg_lib-1.3.1/video.c	Tue Aug 31 23:11:56 1999
@@ -49,6 +49,10 @@
 #include "proto.h"
 #include "my_dmalloc.h"
 
+#ifdef _HAVE_PARAM_H
+#include <sys/param.h>
+#endif
+
 /* Declarations of functions. */
 static void ReconIMBlock(VidStream *,int);
 static void ReconPMBlock(VidStream *,int,int,int,int);
@@ -445,7 +449,9 @@
   static int num_calls = 0;
   unsigned int data;
   int i, status;
+#if BSD < 199103
   long int ftell (FILE *stream);
+#endif
 
   /* If vid_stream is null, create new VidStream structure. */
 
