--- src/tagger_mp3.cpp.orig	Mon Feb 17 00:01:44 2003
+++ src/tagger_mp3.cpp	Mon Nov 24 21:00:58 2003
@@ -448,7 +448,7 @@
 	if(mp3->id3.comment[28] == '\0') {
 	  mp3->id3.track[0] = mp3->id3.comment[29];
 	}
-	mp3->file.readBlock(&(char)mp3->id3.genre[0], 1);
+	mp3->file.readBlock((char*)&mp3->id3.genre[0], 1);
 	unpad(mp3->id3.title);
 	unpad(mp3->id3.artist);
 	unpad(mp3->id3.album);
