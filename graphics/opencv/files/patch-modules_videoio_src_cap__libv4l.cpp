--- modules/videoio/src/cap_libv4l.cpp.orig	2016-12-23 12:54:44 UTC
+++ modules/videoio/src/cap_libv4l.cpp
@@ -251,7 +251,9 @@ make & enjoy!
 #include <sys/mman.h>
 #include <string.h>
 #include <stdlib.h>
+#ifdef __linux__
 #include <asm/types.h>          /* for videodev2.h */
+#endif
 #include <assert.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
@@ -298,12 +300,12 @@ static unsigned int n_buffers = 0;
 /* TODO: Consider at program exit return controls to the initial values - See v4l2_free_ranges function */
 /* TODO: Consider at program exit reset the device to default values - See v4l2_free_ranges function */
 typedef struct v4l2_ctrl_range {
-  __u32 ctrl_id;
-  __s32 initial_value;
-  __s32 current_value;
-  __s32 minimum;
-  __s32 maximum;
-  __s32 default_value;
+  uint32_t ctrl_id;
+  int32_t initial_value;
+  int32_t current_value;
+  int32_t minimum;
+  int32_t maximum;
+  int32_t default_value;
 } v4l2_ctrl_range;
 
 typedef struct CvCaptureCAM_V4L
@@ -542,7 +544,7 @@ static void v4l2_add_ctrl_range(CvCaptur
   capture->v4l2_ctrl_ranges = (v4l2_ctrl_range**)realloc((v4l2_ctrl_range**)capture->v4l2_ctrl_ranges, (capture->v4l2_ctrl_count + 1) * sizeof(v4l2_ctrl_range*));
 }
 
-static int v4l2_get_ctrl_default(CvCaptureCAM_V4L* capture, __u32 id) {
+static int v4l2_get_ctrl_default(CvCaptureCAM_V4L* capture, uint32_t id) {
   int i;
   for (i = 0; i < capture->v4l2_ctrl_count; i++) {
     if (id == capture->v4l2_ctrl_ranges[i]->ctrl_id) {
@@ -552,7 +554,7 @@ static int v4l2_get_ctrl_default(CvCaptu
   return -1;
 }
 
-static int v4l2_get_ctrl_min(CvCaptureCAM_V4L* capture, __u32 id) {
+static int v4l2_get_ctrl_min(CvCaptureCAM_V4L* capture, uint32_t id) {
   int i;
   for (i = 0; i < capture->v4l2_ctrl_count; i++) {
     if (id == capture->v4l2_ctrl_ranges[i]->ctrl_id) {
@@ -562,7 +564,7 @@ static int v4l2_get_ctrl_min(CvCaptureCA
   return -1;
 }
 
-static int v4l2_get_ctrl_max(CvCaptureCAM_V4L* capture, __u32 id) {
+static int v4l2_get_ctrl_max(CvCaptureCAM_V4L* capture, uint32_t id) {
   int i;
   for (i = 0; i < capture->v4l2_ctrl_count; i++) {
     if (id == capture->v4l2_ctrl_ranges[i]->ctrl_id) {
@@ -575,7 +577,7 @@ static int v4l2_get_ctrl_max(CvCaptureCA
 
 static void v4l2_scan_controls(CvCaptureCAM_V4L* capture) {
 
-  __u32 ctrl_id;
+  uint32_t ctrl_id;
   struct v4l2_control c;
   if (capture->v4l2_ctrl_ranges != NULL) {
     v4l2_free_ranges(capture);
@@ -1653,7 +1655,7 @@ static int icvSetVideoSize( CvCaptureCAM
 
 static int icvSetControl (CvCaptureCAM_V4L* capture, int property_id, double value) {
   struct v4l2_control c;
-  __s32 ctrl_value;
+  int32_t ctrl_value;
   char name[32];
   int is_v4l2  = 1;
   int v4l2_min = 0;
