--- src/tools/add_image.cc.orig	2010-04-30 09:32:18 UTC
+++ src/tools/add_image.cc
@@ -104,10 +104,10 @@ namespace {
 
 			png_read_info(png_ptr, info_ptr);
 
-			size.x = info_ptr->width;
-			size.y = info_ptr->height;
-			color_type = info_ptr->color_type;
-			bit_depth = info_ptr->bit_depth;
+			size.x = png_get_image_width(png_ptr, info_ptr);
+			size.y = png_get_image_height(png_ptr, info_ptr);
+			bit_depth = png_get_bit_depth(png_ptr, info_ptr);
+			color_type = png_get_color_type(png_ptr, info_ptr);
 
 			number_of_passes = png_set_interlace_handling(png_ptr);
 			png_read_update_info(png_ptr, info_ptr);
@@ -116,13 +116,13 @@ namespace {
 			if (setjmp(png_jmpbuf(png_ptr)))
 				return;
 
-			scoped_array<png_byte>  raw_buf (new png_byte [info_ptr->rowbytes]);
-			for (size_t y = 0; y < info_ptr->height; y++)
+			scoped_array<png_byte>  raw_buf (new png_byte [png_get_rowbytes(png_ptr, info_ptr)]);
+			for (size_t y = 0; y < png_get_image_height(png_ptr, info_ptr); y++)
 			{
 				png_bytep bufp = raw_buf.get();
 				png_bytepp bufpp = &bufp;
 				png_read_rows (png_ptr, bufpp, NULL, 1);
-				std::copy (&raw_buf[0], &raw_buf[info_ptr->rowbytes], std::back_inserter (buf));
+				std::copy (&raw_buf[0], &raw_buf[png_get_rowbytes(png_ptr, info_ptr)], std::back_inserter (buf));
 			}
 
 	        fclose(fp);
@@ -132,7 +132,7 @@ namespace {
 	};
 
 	struct _add {
-		void operator () (shared_ptr<CPage> page, 
+		void operator () (boost::shared_ptr<CPage> page, 
 						  const Position& where, 
 						  Point image_dim, 
 						  size_t bit_depth, 
@@ -191,14 +191,14 @@ main(int argc, char ** argv)
 				return 1;
 
 		// open pdf
-		shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
+		boost::shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
 
 		if (pdf->isLinearized())
 		{
 			pdf.reset ();
 			string out (file+"-delinearised.pdf");
 			{
-				shared_ptr<Delinearizator> del (Delinearizator::getInstance(file.c_str(), new OldStylePdfWriter));
+				boost::shared_ptr<Delinearizator> del (Delinearizator::getInstance(file.c_str(), new OldStylePdfWriter));
 					if (!del) return -1;
 				del->delinearize(out.c_str());
 			}
@@ -226,7 +226,7 @@ main(int argc, char ** argv)
 					continue;
 				}
 
-			shared_ptr<CPage> page = pdf->getPage(*it);
+			boost::shared_ptr<CPage> page = pdf->getPage(*it);
 			_add()(page, pos, _png.size, _png.bit_depth, _png.buf);
 
 			#ifdef WIN32
