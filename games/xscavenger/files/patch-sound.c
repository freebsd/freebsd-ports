--- sound.c.orig	2014-11-18 23:26:13 UTC
+++ sound.c
@@ -10,7 +10,13 @@
 #include <string.h>
 #include <errno.h>
 
+#ifdef NO_ALSA
+#include <sys/ioctl.h>
+#include <sys/soundcard.h>
+#define SOUNDDEV "/dev/dsp"
+#else
 #include <alsa/asoundlib.h>
+#endif
 
 
 #include "scav.h"
@@ -42,10 +48,14 @@ sample samples[NUMSOUNDS];
 
 int soundworking=0;
 int fragment;
+#ifdef NO_ALSA
+int dsp;
+#endif
 int soundwrite,soundread;
 int *soundbuffer;
 int soundbufferlen;
 
+#ifndef NO_ALSA
 snd_pcm_t *playback_handle;
 
 void opendsp(int samplerate)
@@ -122,6 +132,7 @@ void opendsp(int samplerate)
 	}
 
 }
+#endif
 
 
 void soundinit(void)
@@ -129,26 +140,50 @@ void soundinit(void)
 	int fd[2];
 	char devname[256];
 	int value;
+#ifndef NO_ALSA
 	int res;
+#endif
 
 	sprintf(dirlist,"%s/%s,%s",localname,localdirname,libname);
 	soundworking=0;
+#ifdef NO_ALSA
+	pipe(fd);
+#else
 	res=pipe(fd);res=res;//STFU
+#endif
 	soundread=fd[0];
 	soundwrite=fd[1];
+#ifdef NO_ALSA
+	if(fork())
+#else
 	res = fork();
 	if(res>0)
+#endif
 	{
 		close(soundread);
 		return;
 	}
 	close(soundwrite);
 	memset(samples,0,sizeof(samples));
+#ifdef NO_ALSA
+	strcpy(devname,SOUNDDEV);
+	dsp=open(devname,O_WRONLY);
+	if(dsp<0) goto failed;
+	fragment=0x20009;
+	ioctl(dsp,SNDCTL_DSP_SETFRAGMENT,&fragment);
+	value=10000;
+	ioctl(dsp,SNDCTL_DSP_SPEED,&value);
+	value=0;
+	ioctl(dsp,SNDCTL_DSP_STEREO,&value);
+	ioctl(dsp,SNDCTL_DSP_GETBLKSIZE,&fragment);
+	if(!fragment) {close(dsp);goto failed;}
+#else
 
 // 10,000 hz mono 8bit samples
 	fragment = 256;
 	opendsp(10000);
 
+#endif
 	soundbufferlen=fragment*sizeof(int);
 	soundbuffer=malloc(soundbufferlen);
 	if(!soundbuffer) goto failed;
@@ -180,12 +215,21 @@ int i,file,size,len;
 	}
 	size=lseek(file,0,SEEK_END);
 	lseek(file,0,SEEK_SET);
+#ifdef NO_ALSA
+	len=samples[num].len=(size+fragment-1)/fragment;
+#else
 	int expand = 1;
 	len=samples[num].len=(size*expand+fragment-1)/fragment;
+#endif
 	len*=fragment;
 	p1=samples[num].data=malloc(len);
 	if(p1)
 	{
+#ifdef NO_ALSA
+		i=read(file,p1,size);
+		if(len-size) memset(p1+size,0,len-size);
+		while(size--) *p1++ ^= 0x80;
+#else
 		memset(p1, 0, len);
 		int got=read(file,p1,size);
 		for(i=got-1;i>=0;--i)
@@ -194,6 +238,7 @@ int i,file,size,len;
 			for(j=expand-1;j>=0;--j)
 				p1[i*expand+j] = p1[i] - 0x80;
 		}
+#endif
 	} else
 		samples[num].data=0;
 	close(file);
@@ -207,8 +252,12 @@ signed char *p;
 int *ip;
 int playing[MIXMAX],position[MIXMAX];
 int which;
+#ifdef NO_ALSA
+unsigned char clip[8192];
+#else
 int *mixbuffer;
 short *outbuffer;
+#endif
 
 	while(!soundworking)
 	{
@@ -223,12 +272,21 @@ short *outbuffer;
 		com=*commands;
 		if(com==SOUND_EXIT) exit(0);
 	}
+#ifdef NO_ALSA
+	for(i=0;i<8192;i++)
+	{
+		j=i-4096;
+		clip[i]=j > 127 ? 255 : (j<-128 ? 0 : j+128);
+	}
+#endif
 	for(i=0;i<NUMSOUNDS;++i)
 		readsound(i);
 	memset(playing,0,sizeof(playing));
 	memset(position,0,sizeof(position));
+#ifndef NO_ALSA
 	mixbuffer = malloc(fragment * sizeof(*mixbuffer));
 	outbuffer = malloc(fragment * sizeof(*outbuffer));
+#endif
 	for(;;)
 	{
 		commandlen=read(soundread,commands,64);
@@ -238,10 +296,18 @@ short *outbuffer;
 			commandlen=0;
 			if(errno==EPIPE) exit(0);
 		} else if(commandlen==0) exit(0);
+#ifdef NO_ALSA
+		p=commands;
+#else
 		signed char *comp=commands;
+#endif
 		while(commandlen--)
 		{
+#ifdef NO_ALSA
+			com=*p++;
+#else
 			com=*comp++;
+#endif
 			if(com==SOUND_QUIET) {memset(position,0,sizeof(position));continue;}
 			if(com==SOUND_EXIT) exit(0);
 			if(com<NUMSOUNDS)
@@ -261,7 +327,11 @@ short *outbuffer;
 						position[i]=0;
 			}
 		}
+#ifdef NO_ALSA
+		memset(soundbuffer,0,soundbufferlen);
+#else
 		memset(mixbuffer, 0, fragment * sizeof(*mixbuffer));
+#endif
 		for(i=0;i<MIXMAX;++i)
 		{
 			if(!position[i]) continue;
@@ -274,6 +344,17 @@ short *outbuffer;
 			p=samples[which].data;
 			if(!p) continue;
 			p+=fragment*(position[i]++ -1);
+#ifdef NO_ALSA
+			ip=soundbuffer;
+			j=fragment;
+			while(j--) *ip++ += *p++;
+		}
+		j=fragment;
+		ip=soundbuffer;
+		p=(char *) soundbuffer;
+		while(j--) *p++ = clip[4096+*ip++];
+		write(dsp,(char *)soundbuffer,fragment);
+#else
 
 			for(j=0;j<fragment;++j)
 				mixbuffer[j] += 255*p[j];
@@ -289,15 +370,22 @@ short *outbuffer;
 		res = snd_pcm_writei(playback_handle, outbuffer, fragment);
 //printf("res=%d\n", res);
 
+#endif
 	}
 }
 
 void playsound(int n)
 {
 	char c;
+#ifndef NO_ALSA
 	int res;
+#endif
 	c=n;
+#ifdef NO_ALSA
+	write(soundwrite,&c,1);
+#else
 	res=write(soundwrite,&c,1);res=res;//STFU
+#endif
 }
 
 void endsound(void)
