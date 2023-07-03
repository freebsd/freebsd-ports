--- core/libs/metadataengine/engine/metaengine_comments.cpp.orig	2023-03-12 13:19:02 UTC
+++ core/libs/metadataengine/engine/metaengine_comments.cpp
@@ -64,7 +64,7 @@ bool MetaEngine::canWriteComment(const QString& filePa
     catch (Exiv2::AnyError& e)
     {
         qCCritical(DIGIKAM_METAENGINE_LOG) << "Cannot check Comment access mode with Exiv2 (Error #"
-                                           << e.code() << ": " << QString::fromStdString(e.what()) << ")";
+                                           << static_cast<int>(e.code()) << ": " << QString::fromStdString(e.what()) << ")";
     }
     catch (...)
     {
