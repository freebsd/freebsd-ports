--- examples/getalbum.c.orig	Wed Mar 17 00:05:57 2004
+++ examples/getalbum.c	Wed Mar 17 00:06:35 2004
@@ -30,7 +30,7 @@
 {
     musicbrainz_t o;
     char          error[256], data[256], temp[256], *args[2];
-    int           ret, numTracks, trackNum, i, isMultipleArtist = 0;
+    int           ret, numTracks, numDates, trackNum, i, isMultipleArtist = 0;
 
     if (argc < 2)
     {
@@ -141,7 +141,7 @@
     if (mb_GetResultData(o, MBE_AlbumGetAmazonCoverartURL, data, 256))
        printf("CoverartURL: %s\n", data);
 
-    int numDates = mb_GetResultInt(o, MBE_AlbumGetNumReleaseDates);
+    numDates = mb_GetResultInt(o, MBE_AlbumGetNumReleaseDates);
     for(i = 1; i <= numDates; i++)
     {
         // Select the first release date
