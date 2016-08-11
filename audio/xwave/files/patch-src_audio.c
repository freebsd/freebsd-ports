--- src/audio.c.orig	1998-11-08 23:22:55 UTC
+++ src/audio.c
@@ -37,8 +37,8 @@
 #ifdef linux
 #include <linux/soundcard.h>
 
-#elif defined(FreeBSD)
-#include <machine/soundcard.h>
+#elif defined(__FreeBSD__)
+#include <sys/soundcard.h>
 
 #elif defined(sgi)
 #include <dmedia/audio.h>
@@ -55,7 +55,7 @@
 #include "sample_settings.h"
 #include "audio.h"
 
-#if defined(linux) || defined (FreeBSD) || defined(sun) 
+#if defined(linux) || defined (__FreeBSD__) || defined(sun) 
 static int set_dsp(int o_mode,int res,int channels,int freq,int *buf_size);
 #endif
 
@@ -67,7 +67,7 @@ extern AppResources app_resources;
 static Audio_File af;
 static int stop_record;
 
-#if defined (linux) || defined (FreeBSD)
+#if defined (linux) || defined (__FreeBSD__)
 int set_dsp(int o_mode,int res, int channels, int freq, int *buf_size)
 {
     int check;
@@ -369,7 +369,7 @@ int get_samples(byte* audio_buffer,int m
 
 void play_file(char *fname,Main_Bool *mb)
 {
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
     int audio;
 #elif defined(sgi)
     ALport port;
@@ -383,7 +383,7 @@ void play_file(char *fname,Main_Bool *mb
 	return;
     }
     
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
     if ((audio=set_dsp(O_WRONLY,af.bps,af.channels,af.freq,&buf_size))==-1) {
 	fprintf(stderr,"XWave: Error ! Cannot set dsp !\n");
 	close(af.fd);
@@ -403,7 +403,7 @@ void play_file(char *fname,Main_Bool *mb
     if ((buffer=malloc(buf_size))==NULL) {
 	fprintf(stderr,"XWave: Error ! Cannot alloc mem !\n");
 	close(af.fd);
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 	close(audio);
 #elif defined(sgi)
 	ALcloseport(port);
@@ -412,7 +412,7 @@ void play_file(char *fname,Main_Bool *mb
 	return;
     }
     
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
     while ((length=af_read(af,buffer,buf_size))>0) {
 	if (write(audio, buffer, length)==-1) break;
     }
@@ -439,7 +439,7 @@ void OLD_play_buffer(Main_Data *md)
     int offset=0,playlength,length;
 #ifdef sgi
     ALport port;
-#elif defined(linux) || defined (FreeBSD) || defined (sun)
+#elif defined(linux) || defined (__FreeBSD__) || defined (sun)
     int audio;
     
     if ((audio=set_dsp(O_WRONLY,wd->res,wd->channels,wd->freq,&buf_size))==-1) {
@@ -472,7 +472,7 @@ void OLD_play_buffer(Main_Data *md)
         buffer=wd->buffer+offset;
         while (playlength>0) {
             if (playlength<buf_size) buf_size=playlength;
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
             if (write(audio, buffer, buf_size)==-1) {
                 close(audio);
                 kill((pid_t) getppid(),SIGUSR1);
@@ -497,7 +497,7 @@ void OLD_play_buffer(Main_Data *md)
         wd2af(wd,&af);
         af_rewind(af);
         if (af_seek(af,offset,SEEK_CUR)==AF_ERROR) {
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
             close(audio);
 #elif defined(sgi)
             ALcloseport(port);
@@ -510,7 +510,7 @@ void OLD_play_buffer(Main_Data *md)
         while (playlength>0) {
             if (playlength<buf_size) buf_size=playlength;
             if ((length=af_read(af,(char*) md->mg->fbuf,buf_size))==-1) {
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
                 close(audio);
 #elif defined(sgi)
                 ALcloseport(port);
@@ -518,7 +518,7 @@ void OLD_play_buffer(Main_Data *md)
                 kill((pid_t) getppid(),SIGUSR1);
                 return;
             }
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
             if (write(audio,(char*) md->mg->fbuf,length)==-1) {
                 close(audio);
                 kill((pid_t) getppid(),SIGUSR1);
@@ -537,7 +537,7 @@ void OLD_play_buffer(Main_Data *md)
         }
     }
     
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
     close(audio);
 #elif defined(sgi)
     while (ALgetfilled(port)) sginap(2);
@@ -558,7 +558,7 @@ void play_buffer(Main_Data *md)
     int offset=0,playlength,length;
 #ifdef sgi
     ALport port;
-#elif defined(linux) || defined (FreeBSD) || defined (sun)
+#elif defined(linux) || defined (__FreeBSD__) || defined (sun)
     int audio;
     
     if ((audio=set_dsp(O_WRONLY,wd->res,wd->channels,wd->freq,&buf_size))==-1) {
@@ -593,7 +593,7 @@ void play_buffer(Main_Data *md)
 	((int *)shared_playpos)[0] = wd->playbeg*wd->bpspl;
 	while (playlength>0) {
 	    if (playlength<buf_size) buf_size=playlength;
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 	    if (write(audio, buffer, buf_size)==-1) {
 		((int *)shared_playpos)[0] = -1;
 		close(audio);
@@ -621,7 +621,7 @@ void play_buffer(Main_Data *md)
 	af_rewind(af);
 	if (af_seek(af,offset,SEEK_CUR)==AF_ERROR) {
 	    ((int *)shared_playpos)[0] = -1;
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 	    close(audio);
 #elif defined(sgi)
 	    ALcloseport(port);
@@ -636,7 +636,7 @@ void play_buffer(Main_Data *md)
 	    if (playlength<buf_size) buf_size=playlength;
 	    if ((length=af_read(af,(char*) md->mg->fbuf,buf_size))==-1) {
 		((int *)shared_playpos)[0] = -1;
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 		close(audio);
 #elif defined(sgi)
 		ALcloseport(port);
@@ -644,7 +644,7 @@ void play_buffer(Main_Data *md)
 		kill((pid_t) getppid(),SIGUSR1);
 		return;
 	    }
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 	    if (write(audio,(char*) md->mg->fbuf,length)==-1) {
 		((int *)shared_playpos)[0] = -1;
 		close(audio);
@@ -666,7 +666,7 @@ void play_buffer(Main_Data *md)
     }
     
     ((int *)shared_playpos)[0] = -1;
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
     close(audio);
 #elif defined(sgi)
     while (ALgetfilled(port)) sginap(2);
@@ -686,7 +686,7 @@ void rec_file(byte res,byte mode,int fre
     void write_length();
     byte *data=NULL;
     int abuf_size,count;
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
     int audio;
     
     if ((audio=set_dsp(O_RDONLY,res,mode,freq,&abuf_size))==-1) {
@@ -707,7 +707,7 @@ void rec_file(byte res,byte mode,int fre
     
     if ((data = (byte *) malloc(abuf_size)) == NULL) {
 	fprintf(stderr,"XWave: Error while alloc mem for audio_buffer !\n");
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 	close(audio);
 #elif defined(sgi)
 	ALcloseport(port);
@@ -725,7 +725,7 @@ void rec_file(byte res,byte mode,int fre
     
     if (af_open(fname,&af,AF_NEW)==AF_ERROR) {
 	free(data);
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 	close(audio);
 #elif defined(sgi)
 	ALcloseport(port);
@@ -738,7 +738,7 @@ void rec_file(byte res,byte mode,int fre
     signal(SIGUSR1,write_length);
     
     while(1) {
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 	if ((count=read(audio, data, abuf_size))==-1) {
 	    close(audio);
 	    af_close(af);
@@ -762,7 +762,7 @@ void rec_file(byte res,byte mode,int fre
 	    return;
 	}
 	if ((count=af_write(af,(char*)data,count))==AF_ERROR) {
-#if defined (linux) || defined (FreeBSD) || defined (sun)
+#if defined (linux) || defined (__FreeBSD__) || defined (sun)
 	    close(audio);
 #elif defined(sgi)
 	    ALcloseport(port);
