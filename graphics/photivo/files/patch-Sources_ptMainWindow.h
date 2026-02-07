Fix build against exiv2-0.27

--- Sources/ptMainWindow.h.orig	2019-03-09 08:00:46 UTC
+++ Sources/ptMainWindow.h
@@ -42,6 +42,7 @@
 #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 #include <exiv2/image.hpp>
 #pragma GCC diagnostic pop
+#include <exiv2/exiv2.hpp>
 
 #include <memory>
 using std::unique_ptr;
