--- ./modules/python/src2/cv2.cv.hpp.orig	2013-10-22 17:54:10.000000000 -0400
+++ ./modules/python/src2/cv2.cv.hpp	2013-10-22 17:55:03.000000000 -0400
@@ -2169,7 +2169,7 @@
 static int convert_to_CvNextEdgeType(PyObject *o, CvNextEdgeType *dst, const char *name = "no_name")
 {
   if (!PyInt_Check(o)) {
-    *dst = (CvNextEdgeType)NULL;
+    *dst = (CvNextEdgeType)0;
     return failmsg("Expected number for CvNextEdgeType argument '%s'", name);
   } else {
     *dst = (CvNextEdgeType)PyInt_AsLong(o);
