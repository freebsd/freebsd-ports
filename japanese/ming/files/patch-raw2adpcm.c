--- ../util/raw2adpcm.c.orig	Thu Oct 16 11:25:25 2003
+++ ../util/raw2adpcm.c	Thu Oct 16 11:26:25 2003
@@ -178,17 +178,16 @@
   int i;
 
   if (argc < 3) {
-    printf("\
-%s converts a raw sound data to adpcm compressed.
-
-Usage:
-%s in out [16bit] [stereo]
-
-in     : the filename of input file, raw sound data
-out    : the filename of output file, ADPCM compressed
-16bit  : bits per sample     0=8bit 1=16bit   default=1=16bit
-stereo : number of channels  0=mono 1=stereo  default=1=stereo
-", argv[0], argv[0]);
+    printf("\n");
+    printf("%s converts a raw sound data to adpcm compressed.\n", argv[0]);
+    printf("\n");
+    printf("Usage:\n");
+    printf("%s in out [16bit] [stereo]\n", argv[0]);
+    printf("\n");
+    printf("in     : the filename of input file, raw sound data\n");
+    printf("out    : the filename of output file, ADPCM compressed\n");
+    printf("16bit  : bits per sample     0=8bit 1=16bit   default=1=16bit\n");
+    printf("stereo : number of channels  0=mono 1=stereo  default=1=stereo\n");
     exit(0);
   }
 
