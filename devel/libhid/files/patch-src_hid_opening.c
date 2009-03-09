--- src/hid_opening.c.orig	2009-03-07 20:28:09.000000000 +0300
+++ src/hid_opening.c	2009-03-07 20:29:17.000000000 +0300
@@ -1,5 +1,6 @@
 #define HID_INTERNAL
 
+#include <stdlib.h>
 #include <hid.h>
 #include <hid_helpers.h>
 #include <os.h>
