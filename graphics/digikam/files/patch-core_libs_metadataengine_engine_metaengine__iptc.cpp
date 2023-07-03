--- core/libs/metadataengine/engine/metaengine_iptc.cpp.orig	2023-03-12 13:19:02 UTC
+++ core/libs/metadataengine/engine/metaengine_iptc.cpp
@@ -29,6 +29,8 @@
 #include "digikam_debug.h"
 #include "digikam_config.h"
 
+#include <exiv2/photoshop.hpp>
+
 #if defined(Q_CC_CLANG)
 #   pragma clang diagnostic push
 #   pragma clang diagnostic ignored "-Wdeprecated-declarations"
@@ -65,7 +67,7 @@ bool MetaEngine::canWriteIptc(const QString& filePath)
     catch (Exiv2::AnyError& e)
     {
         qCCritical(DIGIKAM_METAENGINE_LOG) << "Cannot check Iptc access mode with Exiv2:(Error #"
-                                           << e.code() << ": " << QString::fromStdString(e.what()) << ")";
+                                           << static_cast<int>(e.code()) << ": " << QString::fromStdString(e.what()) << ")";
     }
     catch (...)
     {
@@ -121,7 +123,7 @@ QByteArray MetaEngine::getIptc(bool addIrbHeader) cons
                 c2 = Exiv2::IptcParser::encode(d->iptcMetadata());
             }
 
-            QByteArray data((const char*)c2.pData_, c2.size_);
+            QByteArray data(reinterpret_cast<const char *>(c2.c_data()), c2.size());
 
             return data;
         }
