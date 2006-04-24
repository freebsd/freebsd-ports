--- digikam/kioslave/digikamdates.cpp.orig	Mon Apr 24 17:00:27 2006
+++ digikam/kioslave/digikamdates.cpp	Mon Apr 24 17:01:39 2006
@@ -248,7 +248,7 @@ void kio_digikamdates::special(const QBy
                 *os << dirid;
                 *os << name;
                 *os << date;
-                *os << stbuf.st_size;
+                *os << static_cast<size_t>(stbuf.st_size);
                 *os << dims;
 
                 count++;
