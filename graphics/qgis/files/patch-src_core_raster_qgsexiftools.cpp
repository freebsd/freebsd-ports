--- src/core/raster/qgsexiftools.cpp.orig	2023-05-26 12:01:43 UTC
+++ src/core/raster/qgsexiftools.cpp
@@ -66,7 +66,7 @@ QVariant decodeXmpData( const QString &key, Exiv2::Xmp
       case Exiv2::signedLong:
       case Exiv2::unsignedLongLong:
       case Exiv2::signedLongLong:
-        val = QVariant::fromValue( it->toLong() );
+        val = QVariant::fromValue( it->toInt64() );
         break;
 
       case Exiv2::tiffDouble:
@@ -80,7 +80,7 @@ QVariant decodeXmpData( const QString &key, Exiv2::Xmp
       case Exiv2::signedByte:
       case Exiv2::tiffIfd:
       case Exiv2::tiffIfd8:
-        val = QVariant::fromValue( static_cast< int >( it->toLong() ) );
+        val = QVariant::fromValue( static_cast< int >( it->toInt64() ) );
         break;
 
       case Exiv2::date:
@@ -182,7 +182,7 @@ QVariant decodeExifData( const QString &key, Exiv2::Ex
       case Exiv2::signedLong:
       case Exiv2::unsignedLongLong:
       case Exiv2::signedLongLong:
-        val = QVariant::fromValue( it->toLong() );
+        val = QVariant::fromValue( it->toInt64() );
         break;
 
       case Exiv2::tiffDouble:
@@ -196,7 +196,7 @@ QVariant decodeExifData( const QString &key, Exiv2::Ex
       case Exiv2::signedByte:
       case Exiv2::tiffIfd:
       case Exiv2::tiffIfd8:
-        val = QVariant::fromValue( static_cast< int >( it->toLong() ) );
+        val = QVariant::fromValue( static_cast< int >( it->toInt64() ) );
         break;
 
       case Exiv2::date:
