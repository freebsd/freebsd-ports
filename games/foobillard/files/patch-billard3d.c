--- src/billard3d.c.orig	Sat Jan 11 02:04:01 2003
+++ src/billard3d.c	Sun Feb 16 16:39:59 2003
@@ -24,7 +24,7 @@
 #include <string.h>
 #include <math.h>
 #include <unistd.h>
-#include <endian.h>
+#include <machine/endian.h>
 
 #ifndef USE_SDL
 #include <GL/glut.h>
@@ -4094,7 +4094,7 @@
        fread( &ball_ball_snd.data[SOUND_NULLOFFS*2], 1, ball_ball_snd.len-SOUND_NULLOFFS*2*2 , f );
        fclose(f);
 
-#if __BYTE_ORDER == __BIG_ENDIAN
+#if _BYTE_ORDER == _BIG_ENDIAN
        {
           char *snd=ball_ball_snd.data;
           for(i=0;i<ball_ball_snd.len;i+=2)
