--- src/uni-exiv2.cpp.orig	2021-11-21 14:49:46 UTC
+++ src/uni-exiv2.cpp
@@ -27,7 +27,7 @@
 
 #define ARRAY_SIZE(array) (sizeof array/sizeof(array[0]))
 
-static Exiv2::Image::AutoPtr cached_image;
+static Exiv2::Image::UniquePtr cached_image;
 
 extern "C"
 void
@@ -35,7 +35,7 @@ uni_read_exiv2_map(const char *uri, void (*callback)(c
 {
     Exiv2::LogMsg::setLevel(Exiv2::LogMsg::mute);
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(uri);
+        Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(uri) };
         if ( image.get() == 0 ) {
             return;
         }
@@ -80,7 +80,7 @@ uni_read_exiv2_map(const char *uri, void (*callback)(c
                 }
             }
         }
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr << "Exiv2: '" << e << "'\n";
     }
 }
@@ -97,13 +97,13 @@ uni_read_exiv2_to_cache(const char *uri)
     }
 
     try {
-        cached_image = Exiv2::ImageFactory::open(uri);
+        cached_image = std::move(Exiv2::ImageFactory::open(uri));
         if ( cached_image.get() == 0 ) {
             return 1;
         }
 
         cached_image->readMetadata();
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr << "Exiv2: '" << e << "'\n";
     }
 
@@ -121,7 +121,7 @@ uni_write_exiv2_from_cache(const char *uri)
     }
 
     try {
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(uri);
+        Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(uri) };
         if ( image.get() == 0 ) {
             return 2;
         }
@@ -133,7 +133,7 @@ uni_write_exiv2_from_cache(const char *uri)
         cached_image.reset(NULL);
 
         return 0;
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr << "Exiv2: '" << e << "'\n";
     }
 
