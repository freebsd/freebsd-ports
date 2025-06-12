--- components/resource/imagemanager.cpp.orig	2023-08-08 09:23:20 UTC
+++ components/resource/imagemanager.cpp
@@ -58,7 +58,7 @@ namespace Resource
 
     }
 
-    bool checkSupported(osg::Image* image, const std::string& filename)
+    bool checkSupported(osg::Image* image)
     {
         switch(image->getPixelFormat())
         {
@@ -83,7 +83,7 @@ namespace Resource
         return true;
     }
 
-    osg::ref_ptr<osg::Image> ImageManager::getImage(const std::string &filename, bool disableFlip)
+    osg::ref_ptr<osg::Image> ImageManager::getImage(std::string_view filename, bool disableFlip)
     {
         const std::string normalized = mVFS->normalizeFilename(filename);
 
@@ -147,7 +147,7 @@ namespace Resource
             osg::ref_ptr<osg::Image> image = result.getImage();
 
             image->setFileName(normalized);
-            if (!checkSupported(image, filename))
+            if (!checkSupported(image))
             {
                 static bool uncompress = (getenv("OPENMW_DECOMPRESS_TEXTURES") != nullptr);
                 if (!uncompress)
