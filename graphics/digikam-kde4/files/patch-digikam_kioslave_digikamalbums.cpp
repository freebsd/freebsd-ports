--- digikam/kioslave/digikamalbums.cpp.orig	Mon Apr 24 17:00:12 2006
+++ digikam/kioslave/digikamalbums.cpp	Mon Apr 24 17:01:13 2006
@@ -206,7 +206,7 @@ void kio_digikamalbums::special(const QB
         os << albumid;
         os << name;
         os << date;
-        os << stbuf.st_size;
+        os << static_cast<size_t>(stbuf.st_size);
         os << dims;
     }
 
