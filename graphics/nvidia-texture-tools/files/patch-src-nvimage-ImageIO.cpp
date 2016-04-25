--- src/nvimage/ImageIO.cpp.orig	2010-05-15 09:12:05 UTC
+++ src/nvimage/ImageIO.cpp
@@ -603,7 +603,7 @@ static void user_read_data(png_structp p
 {
 	nvDebugCheck(png_ptr != NULL);
 	
-	Stream * s = (Stream *)png_ptr->io_ptr;
+	Stream * s = (Stream *)png_get_io_ptr(png_ptr);
 	s->serialize(data, (int)length);
 	
 	if (s->isError()) {
