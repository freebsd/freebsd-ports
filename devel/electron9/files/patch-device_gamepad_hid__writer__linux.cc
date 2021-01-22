--- device/gamepad/hid_writer_linux.cc.orig	2020-05-26 07:48:23 UTC
+++ device/gamepad/hid_writer_linux.cc
@@ -4,6 +4,8 @@
 
 #include "device/gamepad/hid_writer_linux.h"
 
+#include <unistd.h>
+
 #include "base/posix/eintr_wrapper.h"
 
 namespace device {
