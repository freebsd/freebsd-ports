--- xgal.sndsrv.freebsd.c.orig	Sun Apr 12 08:03:21 1998
+++ xgal.sndsrv.freebsd.c	Sun Jul 21 19:10:18 2002
@@ -12,20 +12,24 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <sys/ioctl.h>
-#include <machine/soundcard.h>
+#include <sys/soundcard.h>
 #include <sys/time.h>
 #include <signal.h>
 #include <string.h>
 
 
 
-char *FILENAME[] = {
+static const char *FILENAME[] = {
                      "/explode.raw",
                      "/firetorp.raw",
                      "/shield.raw",
                      "/torphit.raw",
                      "/explode_big.raw",
 		     "/ddloo.raw",
+/* Two more files are now expected by the xgalaga!
+\* The order is given in the sound.h   -mi */
+                    "/warp.raw",
+                    "/smart.raw"
                    };
 
 #define NUM_SOUNDS	(sizeof(FILENAME)/sizeof(char*))
@@ -36,17 +40,15 @@
 
 
 /* Terminate: Signal Handler */
-void quit ()
+static void quit ()
 {
   exit (0);
 }
 
-
-
-void init (int argc, char **argv)
+static void init (int argc, char **argv)
 {
   int i;
-  char s[1024];
+  char s[FILENAME_MAX];
 
   if (argc != 3)
   {
@@ -61,7 +63,7 @@
     if (s[(int)strlen(s) - 1] == '/') FILENAME[i]++;
     strcat (s, FILENAME[i]);
     FILENAME[i] = malloc ((int)strlen (s));
-    strcpy (FILENAME[i],s);
+    strcpy ((char *)FILENAME[i],s);
     sound_buffer[i]=NULL;
     sound_size[i]=0;
   }
@@ -77,12 +79,12 @@
               Should set mono mode
               Error checking                
 */
-int setup_dsp (char *dspdev,int *is_pcsp)
+static int setup_dsp (char *dspdev,int *is_pcsp)
 {
   int dsp, frag, value;
   int mixer;
 
-  dsp = open(dspdev, O_RDWR);
+  dsp = open(dspdev, O_WRONLY);
   if (dsp < 1)
   {
     fprintf (stderr, "xgal.sndsrv: Couldn't open DSP %s\n",dspdev);
@@ -133,13 +135,13 @@
    Eventually I'll look at the xgal signal handlers and
    just trap this.
 */
-int do_nothing(void)
+static int do_nothing(void)
 {
     fprintf(stderr,"xgal.sndsrv: doing nothing, something is broken\n");
     while(1)  sleep (5);
 }
 
-int read_sound(int k)
+static int read_sound(int k)
 {
   int i,fd,size;
 
@@ -173,7 +175,7 @@
 }
 
 
-void do_everything (int dsp, int is_pcsp)
+static void do_everything (int dsp, int is_pcsp)
 {
   char k;
   int i, j ;
@@ -200,8 +202,14 @@
             /*fprintf(stderr,"terminating sound\n");*/ /*DEBUG*/
             terminate = 0;
         } else {
-            if(sound_size[k]==0) read_sound(k);
-            if(sound_size[k]>0 && playnum<16)  {
+ 	     if(k>=NUM_SOUNDS) {
+ 		fprintf(stderr,
+ 		"Not that many sounds known (%d >= %d)\n",
+ 		(int)k, NUM_SOUNDS);
+ 		continue;
+ 	     };
+ 	     if(sound_size[(int)k]==0) read_sound((int)k);
+ 	     if(sound_size[(int)k]>0 && playnum<16)  {
 	        position[playnum]=0;
                 playing[playnum++]=k;
                 /*fprintf(stderr,"sound %d added to play queue\n",playnum-1);*/ /*DEBUG*/
@@ -251,20 +259,18 @@
   }
 }
 
-
-
-void main (argc, argv)
+int main (argc, argv)
 int argc;
 char **argv;
 {
-  int dsp, is_pcsp, ppid;
-  char filename[512];
+  int dsp, is_pcsp;
 
   fcntl(STDIN_FILENO,F_SETFL,O_NONBLOCK);
   init (argc, argv);
   dsp = setup_dsp (argv[2],&is_pcsp);
 
-  if (!dsp) do_nothing();
+  if (dsp<0) do_nothing();
 
   do_everything (dsp, is_pcsp);
+  return 0;
 }
