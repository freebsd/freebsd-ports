--- core/libs/metadataengine/engine/metaengine_data_p.cpp.orig	2023-03-12 13:19:02 UTC
+++ core/libs/metadataengine/engine/metaengine_data_p.cpp
@@ -52,7 +52,7 @@ void MetaEngineData::Private::clear()
     catch (Exiv2::AnyError& e)
     {
         qCCritical(DIGIKAM_METAENGINE_LOG) << "Cannot clear data container with Exiv2 "
-                                           << "(Error #" << e.code() << ": "
+                                           << "(Error #" << static_cast<int>(e.code()) << ": "
                                            << QString::fromStdString(e.what())
                                            << ")";
     }
