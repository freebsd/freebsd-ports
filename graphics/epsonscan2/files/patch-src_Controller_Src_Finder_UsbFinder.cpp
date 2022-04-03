--- src/Controller/Src/Finder/UsbFinder.cpp.orig	2021-11-25 00:56:57 UTC
+++ src/Controller/Src/Finder/UsbFinder.cpp
@@ -25,7 +25,11 @@
 #include "ModelInfo.hpp"
 #include "Utility.hpp"
 extern "C" {
+#if __FreeBSD__
+#include <libusb.h>
+#else
 #include <libusb-1.0/libusb.h>
+#endif
 }
 #include <list>
 #include <iostream>
