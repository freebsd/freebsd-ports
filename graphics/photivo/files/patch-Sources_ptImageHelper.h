Fix build against exiv2-0.27

--- Sources/ptImageHelper.h.orig	2019-03-09 08:02:50 UTC
+++ Sources/ptImageHelper.h
@@ -30,7 +30,7 @@
 #include <QString>
 #include <QImage>
 #include <exiv2/iptc.hpp>
-#include <exiv2/xmp.hpp>
+#include <exiv2/exiv2.hpp>
 
 //==============================================================================
 
