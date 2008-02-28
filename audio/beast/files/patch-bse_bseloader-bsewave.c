--- bse/bseloader-bsewave.c.orig	2008-02-26 23:31:32.000000000 +0100
+++ bse/bseloader-bsewave.c	2008-02-26 23:35:26.000000000 +0100
@@ -111,13 +111,13 @@
 } WaveDsc;
 
 /* BseWaveChunkDsc accessors */
-#define LOADER_TYPE(wcd)        ((wcd)->loader_data[0].uint)
+#define LOADER_TYPE(wcd)        ((wcd)->loader_data[0].u_int)
 #define LOADER_FILE(wcd)        ((wcd)->loader_data[1].ptr)
 #define LOADER_INDEX(wcd)       ((wcd)->loader_data[2].ptr)
-#define LOADER_FORMAT(wcd)      ((wcd)->loader_data[4].uint)
-#define LOADER_BYTE_ORDER(wcd)  ((wcd)->loader_data[5].uint)
-#define LOADER_BOFFSET(wcd)     ((wcd)->loader_data[6].uint)
-#define LOADER_LENGTH(wcd)      ((wcd)->loader_data[7].uint)
+#define LOADER_FORMAT(wcd)      ((wcd)->loader_data[4].u_int)
+#define LOADER_BYTE_ORDER(wcd)  ((wcd)->loader_data[5].u_int)
+#define LOADER_BOFFSET(wcd)     ((wcd)->loader_data[6].u_int)
+#define LOADER_LENGTH(wcd)      ((wcd)->loader_data[7].u_int)
 /* loader types */
 #define AUTO_FILE_MAGIC         (('A' << 24) | ('u' << 16) | ('t' << 8) | 'F')
 #define RAW_FILE_MAGIC          (('R' << 24) | ('a' << 16) | ('w' << 8) | 'F')
