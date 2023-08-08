--- ufraw_exiv2.cc.orig	2021-04-25 05:24:28 UTC
+++ ufraw_exiv2.cc
@@ -50,10 +50,10 @@ extern "C" int ufraw_exif_read_input(ufraw_data *uf)
         uf->inputExifBuf = NULL;
         uf->inputExifBufLen = 0;
 
-        Exiv2::Image::AutoPtr image;
+        Exiv2::Image::UniquePtr image;
         if (uf->unzippedBuf != NULL) {
-            image = Exiv2::ImageFactory::open(
-                        (const Exiv2::byte*)uf->unzippedBuf, uf->unzippedBufLen);
+            image = std::move(Exiv2::ImageFactory::open(
+                        (const Exiv2::byte*)uf->unzippedBuf, uf->unzippedBufLen));
         } else {
             char *filename = uf_win32_locale_filename_from_utf8(uf->filename);
             image = Exiv2::ImageFactory::open(filename);
@@ -66,7 +66,9 @@ extern "C" int ufraw_exif_read_input(ufraw_data *uf)
         if (exifData.empty()) {
             std::string error(uf->filename);
             error += ": No Exif data found in the file";
-#if EXIV2_TEST_VERSION(0,27,0)
+#if EXIV2_TEST_VERSION(0,28,0)
+            throw Exiv2::Error(Exiv2::ErrorCode::kerErrorMessage, error);
+#elif EXIV2_TEST_VERSION(0,27,0)
             throw Exiv2::Error(Exiv2::kerErrorMessage, error);
 #else
             throw Exiv2::Error(1, error);
@@ -135,7 +137,7 @@ extern "C" int ufraw_exif_read_input(ufraw_data *uf)
         ufraw_message(UFRAW_SET_LOG, "%s\n", stderror.str().c_str());
 
         return UFRAW_SUCCESS;
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr.rdbuf(savecerr);
         std::string s(e.what());
         ufraw_message(UFRAW_SET_WARNING, "%s\n", s.c_str());
@@ -155,8 +157,8 @@ static Exiv2::ExifData ufraw_prepare_exifdata(ufraw_da
         /* Reset orientation tag since UFRaw already rotates the image */
         if ((pos = exifData.findKey(Exiv2::ExifKey("Exif.Image.Orientation")))
                 != exifData.end()) {
-            ufraw_message(UFRAW_SET_LOG, "Resetting %s from '%d' to '1'\n",
-                          pos->key().c_str(), pos->value().toLong());
+            ufraw_message(UFRAW_SET_LOG, "Resetting %s from '%ld' to '1'\n",
+                          pos->key().c_str(), static_cast<long int>(pos->value().toInt64()));
             pos->setValue("1"); /* 1 = Normal orientation */
         }
     }
@@ -327,7 +329,7 @@ extern "C" int ufraw_exif_prepare_output(ufraw_data *u
         ufraw_message(UFRAW_SET_LOG, "%s\n", stderror.str().c_str());
 
         return UFRAW_SUCCESS;
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr.rdbuf(savecerr);
         std::string s(e.what());
         ufraw_message(UFRAW_SET_WARNING, "%s\n", s.c_str());
@@ -347,7 +349,7 @@ extern "C" int ufraw_exif_write(ufraw_data *uf)
 
         char *filename =
             uf_win32_locale_filename_from_utf8(uf->conf->outputFilename);
-        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
+        Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(filename) };
         uf_win32_locale_filename_free(filename);
         assert(image.get() != 0);
 
@@ -367,7 +369,7 @@ extern "C" int ufraw_exif_write(ufraw_data *uf)
         ufraw_message(UFRAW_SET_LOG, "%s\n", stderror.str().c_str());
 
         return UFRAW_SUCCESS;
-    } catch (Exiv2::AnyError& e) {
+    } catch (Exiv2::Error& e) {
         std::cerr.rdbuf(savecerr);
         std::string s(e.what());
         ufraw_message(UFRAW_SET_WARNING, "%s\n", s.c_str());
