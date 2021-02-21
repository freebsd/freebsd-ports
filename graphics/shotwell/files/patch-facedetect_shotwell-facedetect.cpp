--- facedetect/shotwell-facedetect.cpp.orig	2021-02-21 15:22:50 UTC
+++ facedetect/shotwell-facedetect.cpp
@@ -34,7 +34,7 @@ void help() {
 void detectFaces(Mat &img, CascadeClassifier &cascade, double scale) {
 
 	Mat gray;
-	cvtColor(img, gray, CV_BGR2GRAY);
+	cvtColor(img, gray, COLOR_BGR2GRAY);
 
 	Mat smallImg(cvRound(img.rows / scale), cvRound(img.cols / scale), CV_8UC1);
 	Size smallImgSize = smallImg.size();
@@ -43,7 +43,7 @@ void detectFaces(Mat &img, CascadeClassifier &cascade,
 	equalizeHist(smallImg, smallImg);
 
 	vector<Rect> faces;
-	cascade.detectMultiScale(smallImg, faces, 1.1, 2, CV_HAAR_SCALE_IMAGE, Size(30, 30));
+	cascade.detectMultiScale(smallImg, faces, 1.1, 2, CASCADE_SCALE_IMAGE, Size(30, 30));
 
 	int i = 0;
 	for (vector<Rect>::const_iterator r = faces.begin(); r != faces.end(); r++, i++) {
