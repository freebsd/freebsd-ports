--- modplugplay.c.orig	Mon Oct  6 09:33:56 2003
+++ modplugplay.c	Thu Feb  5 20:40:53 2004
@@ -1,8 +1,7 @@
-
 /*
 commandline interface to modplugxmms library
 gurkan@linuks.mine.nu www.linuks.mine.nu
-Copyright (C) 2003 Gürkan Sengün
+Copyright (C) 2003 Gurkan Sengun
 
 TODO
 unlock /dev/dsp when in 'p'ause mode
@@ -151,7 +150,7 @@
 
 void help(char *s)
 {
-	printf("Copyright (C) 2003 Gürkan Sengün\n");
+	printf("Copyright (C) 2003 Gurkan Sengun\n");
         printf("Version %s compiled on %s at %s.\n",VERSION,__DATE__,__TIME__);
 	printf("\n");
 	printf("%s: too few arguments\n",s);
@@ -183,10 +182,10 @@
     char t[sz];
     int i, lit, big;
 
-    for (i=0; i<sz; i++) s[i] = i;
+    for (i=0; i<(int)sz; i++) s[i] = i;
     ival = *(int *)s;
     big = lit = 0;
-    for (i=0; i<sz; i++) {
+    for (i=0; i<(int)sz; i++) {
         char c = ival&0xff;
         ival >>= 8;
         if (s[i] == c) lit++;
@@ -250,6 +249,7 @@
     }
     ioctl(mixer_fd,MIXER_WRITE(SOUND_MIXER_PCM),&newvol);
     close(mixer_fd);
+    return 0;
 }
 
 int main(int argc, char* argv[])
@@ -257,7 +257,7 @@
     FILE *f;
     long size;
     char *d;
-    int ch,x,y;
+    int x,y;
     ModPlugFile *f2;
     int len,mlen;
     struct timeval tvstart;
@@ -269,8 +269,11 @@
     char songname[41];
     char notpaus[4];
     
+    /*
     int vol=getpcmvol();
-    /*printf("V%02x\n",vol);*/
+    printf("V%02x\n",vol);
+    */
+
     /*
     struct count_info ci;
     ioctl(audio_fd,SNDCTL_DSP_GETOPTR,&ci);
@@ -289,7 +292,6 @@
     int channels = 2;
     int speed = 44100;
 
-    int c;
     char buffer[128];
     int result, nread;
     struct pollfd pollfds;
@@ -299,19 +301,10 @@
     int mono=0;
     int bits=0;
     int song;
-    int millisecond;
-    char *randplayed; /* randomly played songs
-			 songs that are n/N'd are done or not? */
     /* what about N if the previous song is not playable? */
     /* maybe mark it played in randplayed */
 
     // [rev--dly--] [sur--dly--] [bas--rng--]
-    int rev=0;    // a
-    int revdly=0; // s
-    int sur=0;    // d
-    int surdly=0; // y
-    int bas=0;    // x
-    int basrng=0; // c
 
     if (get_byteorder()==0) {
 	format=AFMT_S16_LE;
@@ -335,7 +328,7 @@
 
 /*
     if (strstr(argv[1],"-v")) {
-        printf("Copyright (C) 2003 Gürkan Sengün\n");
+        printf("Copyright (C) 2003 Gurkan Sengun\n");
         printf("Version %s compiled on %s at %s.\n",VERSION,__DATE__,__TIME__);
         exit(0);
     }
