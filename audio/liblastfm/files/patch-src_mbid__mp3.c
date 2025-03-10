Silence warning
warning: logical not is only applied to the left hand side of this comparison [-Wlogical-not-parentheses]
      if (!strncmp(head,"ID3",3) == 0) {

--- src/mbid_mp3.c.orig	2014-10-02 14:05:46 UTC
+++ src/mbid_mp3.c
@@ -94,7 +94,7 @@ int getMP3_MBID(const char *path, char mbid[MBID_BUFFE
 
    while (s) {
       mfile(3,head,fp,&s);
-      if (!strncmp(head,"ID3",3) == 0) {
+      if (!(strncmp(head,"ID3",3) == 0)) {
          //debug("No ID3v2 tag found: %s\n",path);
          break;
       }
