--- sound.c.orig	2004-05-26 20:54:16 UTC
+++ sound.c
@@ -50,7 +50,7 @@ UInt32 CycleNew;
 // indicates the last time music has been "released"
 
 /* TODO */
-int BaseClock=7170000;
+extern int BaseClock; // use value set in pce.c
 // int BaseClock = 8992000;
 // the freq of the internal PC Engine CPU
 // the sound use a kind of "relative" frequency
