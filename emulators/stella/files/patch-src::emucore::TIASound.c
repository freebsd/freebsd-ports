--- src/emucore/TIASound.c.orig	Mon Jun 14 04:22:45 2004
+++ src/emucore/TIASound.c	Sun Jul 18 18:43:44 2004
@@ -173,10 +173,12 @@
    uint8 chan;
    int16 n;
 
+   srandom(time(NULL));
+
    /* fill the 9bit polynomial with random bits */
    for (n=0; n<POLY9_SIZE; n++)
    {
-      Bit9[n] = rand() & 0x01;       /* fill poly9 with random bits */
+      Bit9[n] = random() & 0x01;       /* fill poly9 with random bits */
    }
 
    /* calculate the sample 'divide by N' value based on the playback freq. */
