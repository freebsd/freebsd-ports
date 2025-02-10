--- src/Controller/Src/Finder/UsbFinder.cpp.orig	2024-09-12 07:10:37 UTC
+++ src/Controller/Src/Finder/UsbFinder.cpp
@@ -22,7 +22,11 @@ extern "C" {
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
