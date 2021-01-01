--- src/hid_initialisation.c.orig	2009-03-07 20:27:43.000000000 +0300
+++ src/hid_initialisation.c	2009-03-07 20:29:25.000000000 +0300
@@ -4,6 +4,7 @@
 #define HID_INTERNAL
 
 #include "config.h"
+#include <stdlib.h>
 #include <hid.h>
 #include <hid_helpers.h>
 
