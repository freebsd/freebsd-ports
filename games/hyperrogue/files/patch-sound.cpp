--- sound.cpp.orig	2017-04-15 02:52:00 UTC
+++ sound.cpp
@@ -122,7 +122,7 @@ bool loadMusicInfo(string dir) {
     for(int i=0; i<size(dir); i++) if(dir[i] == '/' || dir[i] == '\\')
       dir2 = dir.substr(0, i+1);
     char buf[1000];
-    while(fgets(buf, 800, f) > 0) {
+    while(fgets(buf, 800, f) != NULL) {
       for(int i=0; buf[i]; i++) if(buf[i] == 10 || buf[i] == 13) buf[i] = 0;
       if(buf[0] == '[' && buf[3] == ']') {
         int id = (buf[1] - '0') * 10 + buf[2] - '0';
