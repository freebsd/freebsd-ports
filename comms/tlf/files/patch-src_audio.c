--- src/audio.c.orig	Sat Jul 10 21:31:56 2004
+++ src/audio.c	Sat Jul 10 21:32:05 2004
@@ -578,6 +578,7 @@

 float testvalue;
 char key = '\0';
+int runnit = 1;

 clear();

@@ -586,7 +587,6 @@
 /* ------------initialize sound card --------*/
 init_audio();

-int runnit = 1;

 while (runnit == 1) {

