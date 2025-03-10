--- libemf/libemf.cpp.orig	2020-06-07 13:10:20 UTC
+++ libemf/libemf.cpp
@@ -72,8 +72,7 @@ namespace EMF {
     if ( not bigEndian() ) {
       return a;
     }
-#include <byteswap.h>
-    return bswap_32(a);
+    return __builtin_bswap32(a);
   }
 
   /*!
@@ -980,9 +979,9 @@ extern "C" {
 
     int filename_count = ::strlen( filename );
 
-    std::basic_string<WCHAR> filename_w( filename, filename + filename_count );
+    std::basic_string<char16_t> filename_w( filename, filename + filename_count );
 
-    HENHMETAFILE handle =  GetEnhMetaFileW( filename_w.c_str() );
+    HENHMETAFILE handle =  GetEnhMetaFileW( reinterpret_cast<LPCWSTR>(filename_w.c_str()) );
 
     return handle;
   }
