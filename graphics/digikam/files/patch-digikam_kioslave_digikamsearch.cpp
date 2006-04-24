--- digikam/kioslave/digikamsearch.cpp.orig	Mon Apr 24 17:00:37 2006
+++ digikam/kioslave/digikamsearch.cpp	Mon Apr 24 17:01:58 2006
@@ -214,7 +214,7 @@ void kio_digikamsearch::special(const QB
             *os << dirid;
             *os << name;
             *os << date;
-            *os << stbuf.st_size;
+            *os << static_cast<size_t>(stbuf.st_size);
             *os << dims;
 
             count++;
