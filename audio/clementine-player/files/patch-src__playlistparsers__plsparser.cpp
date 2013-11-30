--- ./src/playlistparsers/plsparser.cpp.orig	2013-11-24 16:01:13.247686715 -0800
+++ ./src/playlistparsers/plsparser.cpp	2013-11-24 16:03:24.812677689 -0800
@@ -46,7 +46,7 @@
       // Use the title and length we've already loaded if any
       if (!songs[n].title().isEmpty())
         song.set_title(songs[n].title());
-      if (!songs[n].length_nanosec() != -1)
+      if (songs[n].length_nanosec() != -1)
         song.set_length_nanosec(songs[n].length_nanosec());
 
       songs[n] = song;
