--- src/modules/mod_magickpp/trgt_magickpp.cpp.orig
+++ src/modules/mod_magickpp/trgt_magickpp.cpp
@@ -53,16 +53,16 @@
 /* === M E T H O D S ======================================================= */
 
 template <class Container>
-MagickLib::Image* copy_image_list(Container& container)
+MagickCore::Image* copy_image_list(Container& container)
 {
 	typedef typename Container::iterator Iter;
-	MagickLib::Image* previous = 0;
-	MagickLib::Image* first = NULL;
-	MagickLib::ExceptionInfo exceptionInfo;
-	MagickLib::GetExceptionInfo(&exceptionInfo);
+	MagickCore::Image* previous = 0;
+	MagickCore::Image* first = NULL;
+	MagickCore::ExceptionInfo exceptionInfo;
+	MagickCore::GetExceptionInfo(&exceptionInfo);
 	for (Iter iter = container.begin(); iter != container.end(); ++iter)
 	{
-		MagickLib::Image* current;
+		MagickCore::Image* current;
 
 		try
 		{
@@ -86,8 +86,8 @@
 
 magickpp_trgt::~magickpp_trgt()
 {
-	MagickLib::ExceptionInfo exceptionInfo;
-	MagickLib::GetExceptionInfo(&exceptionInfo);
+	MagickCore::ExceptionInfo exceptionInfo;
+	MagickCore::GetExceptionInfo(&exceptionInfo);
 
 	try
 	{
@@ -118,7 +118,6 @@
 			for_each(images.begin(), images.end(), Magick::animationDelayImage(delay));
 
 			// optimize the images (only write the pixels that change from frame to frame
-#ifdef HAVE_MAGICK_OPTIMIZE
 			// make a completely new image list
 			// this is required because:
 			//   RemoveDuplicateLayers wants a linked list of images, and removes some of them
@@ -126,7 +125,7 @@
 			//   when we destroy our container, the image is re-freed, failing an assertion
 
 			synfig::info("copying image list");
-			MagickLib::Image *image_list = copy_image_list(images);
+			MagickCore::Image *image_list = copy_image_list(images);
 
 			synfig::info("clearing old image list");
 			images.clear();
@@ -169,18 +168,6 @@
 
 			synfig::info("recreating image list");
 			insertImages(&images, image_list);
-#else
-			synfig::info("not optimizing images");
-			// DeconstructImages is available in ImageMagic 6.2.* but it doesn't take
-			// the 'dispose' method into account, so for frames with transparency where
-			// nothing is moving, we end up with objects disappearing when they shouldn't
-
-			// linkImages(images.begin(), images.end());
-			// MagickLib::Image* new_images = DeconstructImages(images.begin()->image(),&exceptionInfo);
-			// unlinkImages(images.begin(), images.end());
-			// images.clear();
-			// insertImages(&images, new_images);
-#endif
 		}
 		else if (multiple_images)
 		{
