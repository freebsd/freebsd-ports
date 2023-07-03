--- core/libs/metadataengine/engine/metaengine_xmp.cpp.orig	2023-03-12 13:19:02 UTC
+++ core/libs/metadataengine/engine/metaengine_xmp.cpp
@@ -67,7 +67,7 @@ bool MetaEngine::canWriteXmp(const QString& filePath)
     catch (Exiv2::AnyError& e)
     {
         qCCritical(DIGIKAM_METAENGINE_LOG) << "Cannot check Xmp access mode with Exiv2:(Error #"
-                                           << e.code() << ": " << QString::fromStdString(e.what()) << ")";
+                                           << static_cast<int>(e.code()) << ": " << QString::fromStdString(e.what()) << ")";
     }
     catch (...)
     {
@@ -1014,7 +1014,7 @@ QVariant MetaEngine::getXmpTagVariant(const char* xmpT
                 case Exiv2::signedShort:
                 case Exiv2::signedLong:
                 {
-                    return QVariant((int)it->toLong());
+                    return QVariant((int)it->toInt64());
                 }
 
                 case Exiv2::unsignedRational:
