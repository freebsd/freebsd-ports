--- core/libs/metadataengine/engine/metaengine_p.cpp.orig	2023-03-12 13:19:02 UTC
+++ core/libs/metadataengine/engine/metaengine_p.cpp
@@ -542,7 +542,7 @@ bool MetaEngine::Private::saveOperations(const QFileIn
 void MetaEngine::Private::printExiv2ExceptionError(const QString& msg, Exiv2::AnyError& e)
 {
     qCCritical(DIGIKAM_METAENGINE_LOG) << msg.toLatin1().constData()
-                                       << " (Error #" << e.code() << ": " << QString::fromStdString(e.what());
+                                       << " (Error #" << static_cast<int>(e.code()) << ": " << QString::fromStdString(e.what());
 }
 
 void MetaEngine::Private::printExiv2MessageHandler(int lvl, const char* msg)
