--- src/billard3d.c.orig	Sat Nov 15 21:10:47 2003
+++ src/billard3d.c	Sat Nov 15 21:12:13 2003
@@ -24,7 +24,7 @@
 #include <string.h>
 #include <math.h>
 #include <unistd.h>
-#include <endian.h>
+#include <sys/endian.h>
 
 #ifndef USE_SDL
 #include <GL/glut.h>
@@ -4960,7 +4960,7 @@
 
    /* config file */
    load_config( &confv, &confc, argv, argc );
-   while( ( act_option = getopt_long_only(confc, confv, "+", long_options, &option_index) ) >= 0){
+   while( ( act_option = getopt_long(confc, confv, "+", long_options, &option_index) ) >= 0){
        DPRINTF("processing option %d=%s\n",act_option,optarg);
        process_option(act_option);
    }
@@ -5058,7 +5058,7 @@
        fread( &ball_ball_snd.data[SOUND_NULLOFFS*2], 1, ball_ball_snd.len-SOUND_NULLOFFS*2*2 , f );
        fclose(f);
 
-#if __BYTE_ORDER == __BIG_ENDIAN
+#if _BYTE_ORDER == _BIG_ENDIAN
        {
           char *snd=ball_ball_snd.data;
           for(i=0;i<ball_ball_snd.len;i+=2)
