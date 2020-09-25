--- audio.c.orig	2020-09-25 07:48:54 UTC
+++ audio.c
@@ -32,20 +32,8 @@
 #include <sys/types.h>
 #include <math.h>
 
-#ifdef _WIN32
-#include <io.h>
-#else
-# ifndef __MACOSX__
-#  include <sys/io.h>
-# endif
-#endif
-
 #include <fcntl.h>
 
-#ifndef __MACOSX__
-#include <malloc.h>
-#endif
-
 #include "config.h"
 #include "audio.h"
 #include "i18n.h"
@@ -642,7 +630,7 @@ int wav_open(FILE *in, wavegain_opt *opt, unsigned cha
 		if (!find_gain_chunk(in, &len))
 			FSEEK64(in, current_pos, SEEK_SET);
 		else {
-			char buf_double[8];
+			unsigned char buf_double[8];
 			opt->gain_chunk = 1;
 			fread(buf_double, 1, 8, in);
 			opt->gain_scale = READ_D64(buf_double);
