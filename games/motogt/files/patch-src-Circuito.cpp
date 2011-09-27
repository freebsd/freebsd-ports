--- src/Circuito.cpp.orig	2011-01-12 20:20:23.000000000 +0300
+++ src/Circuito.cpp	2011-09-26 23:13:03.000000000 +0400
@@ -171,7 +171,7 @@
 	if (!osd) {image=NULL; sprite=NULL; return; }
 	image = new Image*[image_c];
 	sprite = new Sprite*[image_c];
-	string image_dir=data->tracks[track_index].dir+"t00.png";
+	string image_dir=home_dir + data->tracks[track_index].dir + "t00.png";
 	for (int i=0;i<image_c;i++) {
 		image[i]=new Image[image_r];
 		sprite[i]=new Sprite[image_r];
