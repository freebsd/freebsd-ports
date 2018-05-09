--- ./modules/highgui/include/opencv2/highgui/highgui_c.h.orig	2018-05-02 14:30:32.736476000 -0400
+++ ./modules/highgui/include/opencv2/highgui/highgui_c.h	2018-05-02 14:33:46.169249000 -0400
@@ -136,7 +136,7 @@ CVAPI(void) cvSetWindowProperty(const char* name, int 
 CVAPI(double) cvGetWindowProperty(const char* name, int prop_id);
 
 /* Get window image rectangle coordinates, width and height */
-CVAPI(cv::Rect)cvGetWindowImageRect(const char* name);
+CVAPI(CvRect)cvGetWindowImageRect(const char* name);
 
 /* display image within window (highgui windows remember their content) */
 CVAPI(void) cvShowImage( const char* name, const CvArr* image );
