--- digikam/kioslave/digikamdates.cpp.orig	Tue Apr 11 13:53:08 2006
+++ digikam/kioslave/digikamdates.cpp	Tue Apr 11 13:53:54 2006
@@ -186,7 +186,7 @@
                          .arg(moStr2)
                          .arg(yr,4)
                          .arg(moStr1,2),
-                         &values, false);
+                         &values);
 
             Q_LLONG     imageid;
             QString     name;
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
