--- components/resource/imagemanager.hpp.orig	2023-08-08 09:23:20 UTC
+++ components/resource/imagemanager.hpp
@@ -28,7 +28,7 @@ namespace Resource
 
         /// Create or retrieve an Image
         /// Returns the dummy image if the given image is not found.
-        osg::ref_ptr<osg::Image> getImage(const std::string& filename, bool disableFlip = false);
+        osg::ref_ptr<osg::Image> getImage(std::string_view filename, bool disableFlip = false);
 
         osg::Image* getWarningImage();
 
