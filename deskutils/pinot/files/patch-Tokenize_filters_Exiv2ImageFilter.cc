Fix build with exiv2-0.27

--- Tokenize/filters/Exiv2ImageFilter.cc.orig	2019-03-09 07:44:20 UTC
+++ Tokenize/filters/Exiv2ImageFilter.cc
@@ -25,7 +25,7 @@
 #include <exiv2/image.hpp>
 #include <exiv2/exif.hpp>
 #include <exiv2/iptc.hpp>
-#include <exiv2/xmp.hpp>
+#include <exiv2/exiv2.hpp>
 
 #include "config.h"
 #include "Exiv2ImageFilter.h"
