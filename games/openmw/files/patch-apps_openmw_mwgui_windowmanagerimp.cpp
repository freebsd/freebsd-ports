--- apps/openmw/mwgui/windowmanagerimp.cpp.orig	2023-08-08 09:23:20 UTC
+++ apps/openmw/mwgui/windowmanagerimp.cpp
@@ -2148,7 +2148,7 @@ namespace MWGui
             ResourceImageSetPointerFix* imgSetPointer = resource->castType<ResourceImageSetPointerFix>(false);
             if (!imgSetPointer)
                 continue;
-            std::string tex_name = imgSetPointer->getImageSet()->getIndexInfo(0,0).texture;
+            auto tex_name = imgSetPointer->getImageSet()->getIndexInfo(0,0).texture;
 
             osg::ref_ptr<osg::Image> image = mResourceSystem->getImageManager()->getImage(tex_name);
 
