$FreeBSD$

--- src/s_audio_oss.c.orig	Sat Oct 18 22:44:55 2003
+++ src/s_audio_oss.c	Tue Nov 11 21:15:24 2003
@@ -5,7 +5,7 @@
 
 /* this file inputs and outputs audio using the OSS API available on linux. */
 
-#include <linux/soundcard.h>
+#include <sys/soundcard.h>
 
 #include "m_pd.h"
 #include "s_stuff.h"
