--- src/core/exif.cpp.orig	2022-10-17 19:40:50 UTC
+++ src/core/exif.cpp
@@ -108,7 +108,7 @@ int siril_get_thumbnail_exiv(const char *path, uint8_t
 		//std::cerr << "[exiv2] "<< path << ": found thumbnail "<< preview.width() << "x" << preview.height() << std::endl;
 		memcpy(*buffer, tmp, _size);
 		return 0;
-	} catch (Exiv2::AnyError &e) {
+	} catch (Exiv2::Error &e) {
 		std::string s(e.what());
 		std::cerr << "[exiv2]: " << s << std::endl;
 		return 1;
