--- Tokenize/filters/Exiv2ImageFilter.cc.orig	2022-02-22 20:31:11 UTC
+++ Tokenize/filters/Exiv2ImageFilter.cc
@@ -236,7 +236,7 @@ bool Exiv2ImageFilter::next_document(void)
 
 	try
 	{
-		Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(m_filePath);
+		Exiv2::Image::UniquePtr image { Exiv2::ImageFactory::open(m_filePath) };
 		if (image.get() == NULL)
 		{
 			clog << m_filePath.c_str() << " is not an image" << endl;
@@ -388,7 +388,7 @@ bool Exiv2ImageFilter::next_document(void)
 			}
 		}
 	}
-	catch (Exiv2::AnyError &e)
+	catch (Exiv2::Error &e)
 	{
 		clog << "Caught exiv2 exception: " << e << endl;
 		foundData = false;
