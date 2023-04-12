--- 3rdparty/joystick/jsBSD.cxx.orig	2023-04-07 17:57:15 UTC
+++ 3rdparty/joystick/jsBSD.cxx
@@ -52,6 +52,7 @@
 #include <sys/param.h>
 #include <fcntl.h>
 
+#include <unistd.h>
 #include <string.h>
 #include <errno.h>
 #include <sys/ioctl.h>
@@ -198,6 +199,8 @@ static int joy_initialize_hid(struct os_specific_s *os
     interesting_hid = TRUE;
     if (page == HUP_GENERIC_DESKTOP)
     {
+       int range;
+       int matched;
        switch(usage) {
          case HUG_X:
          case HUG_RX:
@@ -221,6 +224,65 @@ static int joy_initialize_hid(struct os_specific_s *os
              (*num_axes)++;
              os->axes_usage[*num_axes] = usage;
              (*num_axes)++;
+           }
+           range = h.logical_maximum - h.logical_minimum + 1;
+           matched = 0;
+           if (((h.logical_minimum == 0) || (h.logical_minimum == 1)) && (h.unit == HUM_DEGREE) && (h.unit_exponent == 0) && ((range == 4) || (range == 8))) {
+             int resolution = (h.physical_maximum - h.physical_minimum) / (h.logical_maximum - h.logical_minimum);
+             for (int i = h.logical_minimum; i <= h.logical_maximum; i++) {
+               const int degrees = (i - h.logical_minimum) * resolution + h.physical_minimum;
+               switch (degrees) {
+                 case 0:
+                   hatmap_x[i] = 0;
+                   hatmap_y[i] = -1;
+                   matched++;
+                   break;
+                 case 45:
+                   hatmap_x[i] = 1;
+                   hatmap_y[i] = -1;
+                   matched++;
+                   break;
+                 case 90:
+                   hatmap_x[i] = 1;
+                   hatmap_y[i] = 0;
+                   matched++;
+                   break;
+                 case 135:
+                   hatmap_x[i] = 1;
+                   hatmap_y[i] = 1;
+                   matched++;
+                   break;
+                 case 180:
+                   hatmap_x[i] = 0;
+                   hatmap_y[i] = 1;
+                   matched++;
+                   break;
+                 case 225:
+                   hatmap_x[i] = -1;
+                   hatmap_y[i] = 1;
+                   matched++;
+                   break;
+                 case 270:
+                   hatmap_x[i] = -1;
+                   hatmap_y[i] = 0;
+                   matched++;
+                   break;
+                 case 315:
+                   hatmap_x[i] = -1;
+                   hatmap_y[i] = -1;
+                   matched++;
+                   break;
+               }
+             }
+             if (matched == range) {
+               if (h.logical_minimum == 0) {
+                 hatmap_x[h.logical_maximum + 1] = 0;
+                 hatmap_y[h.logical_maximum + 1] = 0;
+               } else {
+                 hatmap_x[0] = 0;
+                 hatmap_y[0] = 0;
+               }
+             }
            }
            break;
          default:
