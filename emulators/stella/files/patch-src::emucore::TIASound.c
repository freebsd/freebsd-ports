--- src/emucore/TIASound.c.orig	Tue Feb 18 02:19:44 2003
+++ src/emucore/TIASound.c	Wed Sep 24 15:51:58 2003
@@ -171,11 +171,13 @@
 {
    uint8 chan;
    int16 n;
-
+
+   srandom(time(NULL));
+
    /* fill the 9bit polynomial with random bits */
    for (n=0; n<POLY9_SIZE; n++)
    {
-      Bit9[n] = rand() & 0x01;       /* fill poly9 with random bits */
+      Bit9[n] = random() & 0x01;       /* fill poly9 with random bits */
    }
 
    /* calculate the sample 'divide by N' value based on the playback freq. */
