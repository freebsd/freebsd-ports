--- imagepool/poolinstance.h.orig	2012-12-13 10:27:07.000000000 +0100
+++ imagepool/poolinstance.h	2012-12-13 10:30:33.000000000 +0100
@@ -49,7 +49,7 @@
 
 	Instance(const std::string& sopinstanceuid);
 
-	friend void ImagePool::remove_instance(const Glib::RefPtr<ImagePool::Instance>&);
+	friend void remove_instance(const Glib::RefPtr<ImagePool::Instance>&);
 
 	friend class ImagePool::Loader;
 
