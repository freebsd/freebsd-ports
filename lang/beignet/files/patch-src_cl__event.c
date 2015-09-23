--- src/cl_event.c.orig	2015-02-03 15:00:21.865295000 +0100
+++ src/cl_event.c	2015-02-03 15:00:30.759495000 +0100
@@ -28,7 +28,7 @@
 #include <assert.h>
 #include <stdio.h>
 
-inline cl_bool
+static inline cl_bool
 cl_event_is_gpu_command_type(cl_command_type type)
 {
   switch(type) {
