--- src/resourcemanager.cpp.orig	2020-08-08 07:23:53 UTC
+++ src/resourcemanager.cpp
@@ -118,15 +118,9 @@ void ResourceManager::initialize(const QString &file, 
 	doc->setRenderHint(Poppler::Document::Antialiasing, true);
 	doc->setRenderHint(Poppler::Document::TextAntialiasing, true);
 	doc->setRenderHint(Poppler::Document::TextHinting, true);
-#if POPPLER_VERSION >= POPPLER_VERSION_CHECK(0, 18, 0)
 	doc->setRenderHint(Poppler::Document::TextSlightHinting, true);
-#endif
-#if POPPLER_VERSION >= POPPLER_VERSION_CHECK(0, 22, 0)
 //	doc->setRenderHint(Poppler::Document::OverprintPreview, true); // TODO what is this?
-#endif
-#if POPPLER_VERSION >= POPPLER_VERSION_CHECK(0, 24, 0)
 	doc->setRenderHint(Poppler::Document::ThinLineSolid, true); // TODO what's the difference between ThinLineSolid and ThinLineShape?
-#endif
 
 	page_count = doc->numPages();
 
