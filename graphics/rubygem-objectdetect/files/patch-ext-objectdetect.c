--- ext/objectdetect.c.orig	2013-05-04 21:19:44.000000000 +0900
+++ ext/objectdetect.c	2013-05-04 21:53:21.000000000 +0900
@@ -5,7 +5,15 @@
 
 #include "cv.h"
 #include "highgui.h"
-#include "ruby.h"
+#ifdef HAVE_RUBY_ST_H
+# include "ruby/ruby.h"
+#else
+# include "ruby.h"
+#endif
+
+#ifndef RSTRING_PTR
+# define RSTRING_PTR(str) (RSTRING(str)->ptr)
+#endif
 
 /*
 call-seq:
@@ -25,13 +33,13 @@
   Check_Type(target_path, T_STRING);
 
   /* load the model */
-  CvHaarClassifierCascade* cascade = cvLoad(RSTRING(model_path)->ptr, 0, 0, 0);
+  CvHaarClassifierCascade* cascade = cvLoad(RSTRING_PTR(model_path), 0, 0, 0);
   if( cascade == 0 ) {
     rb_raise(rb_eArgError, "Can't load the cascade file");
   }
 
   /* load the target picture */
-  IplImage *img = cvLoadImage(RSTRING(target_path)->ptr, 1);
+  IplImage *img = cvLoadImage(RSTRING_PTR(target_path), 1);
   if( !img ) {
     cvReleaseHaarClassifierCascade(&cascade);
     rb_raise(rb_eArgError, "Can't load the image file");
@@ -62,7 +70,7 @@
   CvMemStorage* storage = cvCreateMemStorage(0);
   CvSeq *faces = cvHaarDetectObjects(small_img, cascade, storage,
 				     1.1, 2, CV_HAAR_DO_CANNY_PRUNING,
-				     cvSize(0,0) );
+				     cvSize(0,0), cvSize(0,0) );
 
   /* output */
   VALUE results = rb_ary_new();
