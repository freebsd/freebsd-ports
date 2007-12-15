--- laugh.cpp.orig	2007-02-25 13:36:50.000000000 +0900
+++ laugh.cpp	2007-07-13 01:22:50.000000000 +0900
@@ -117,8 +117,8 @@
     IplImage *frame_copy;
     IplImage *result;
     char window_name[] = "Catcher in the Rye";
-    const char* cascade_name = "haarcascade_frontalface_alt.xml";  //顔検出用のデータが入ってるXMLファイル
-    char mask_name[]="laughingman.bmp";     //マスク画像
+    const char* cascade_name = DATADIR "/haarcascade_frontalface_alt.xml";  //顔検出用のデータが入ってるXMLファイル
+    char mask_name[]=DATADIR "/laughingman.bmp";     //マスク画像
 
     //顔検出データを読み込む
     cascade = (CvHaarClassifierCascade*)cvLoad(cascade_name, 0, 0, 0);
