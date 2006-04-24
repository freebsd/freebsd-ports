--- digikam/kioslave/digikamtags.cpp.orig	Mon Apr 24 17:00:47 2006
+++ digikam/kioslave/digikamtags.cpp	Mon Apr 24 17:02:11 2006
@@ -193,7 +193,7 @@ void kio_digikamtagsProtocol::special(co
         *os << dirid;
         *os << name;
         *os << date;
-        *os << stbuf.st_size;
+        *os << static_cast<size_t>(stbuf.st_size);
         *os << dims;
 
         count++;
