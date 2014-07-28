--- main.c.orig	Sun Oct 22 04:13:23 1995
+++ main.c	Sat Jan 27 15:22:17 2001
@@ -56,6 +56,10 @@
   printf("         Linux Support by Daniel Marks \n");
   printf("           GUS Support by David Jeske (jeske@uiuc.edu)\n");
 #endif /* LINUX */
+#ifdef __FreeBSD__
+  printf("         FreeBSD Support by Vanilla I. Shu \n");
+  printf("           GUS Support by David Jeske (jeske@uiuc.edu\n");
+#endif /* __FreeBSD__ */
 #if defined(__sgi)
   printf("           SGI Support by Mike Muuss (Mike@arl.mil)\n\n");
 #endif /* __sgi */
@@ -69,6 +73,9 @@
 #ifdef LINUX
   printf("     -b 16 bit samples\n");
 #endif /* ?LINUX */
+#ifdef __FreeBSD__
+  printf("     -b 16 bit samples\n");
+#endif /* __FreeBSD__ */
   printf("     -f set frequency\n");
   printf("     -q quiet (don't print anything)\n");
   printf("     -n don't loop\n");
@@ -76,6 +83,9 @@
 #ifdef LINUX
   printf("     -g do NOT use GUS native mode\n");
 #endif /* ?LINUX */
+#ifdef __FreeBSD__
+  printf("     -g do NOT use GUS native mode\n");
+#endif /* __FreeBSD__ */
   printf("     -p PAL speed adjustment (145bpm start)\n");
   printf("s3mod -sbf 44100 foobar.mod\n");
   printf("   plays in stereo, 16 bits, 44.1 kHz\n\n");
@@ -109,7 +119,7 @@
 }
 
 
-void main(int argc, char **argv)
+int main(int argc, char **argv)
 {
   uint32 j;
   char *filename;
@@ -241,6 +251,7 @@
   
   close_dsp_device();
   free(audio_start_buffer);
+  return 0;
 }
 
 
