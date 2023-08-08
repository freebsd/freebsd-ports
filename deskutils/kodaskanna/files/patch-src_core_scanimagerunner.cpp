--- src/core/scanimagerunner.cpp.orig	2022-01-24 22:35:35 UTC
+++ src/core/scanimagerunner.cpp
@@ -10,6 +10,9 @@
 #include "scanresult.hpp"
 #include "scanresult_p.hpp"
 // ZXing
+#include <ZXing/ZXVersion.h>
+#define ZXING_VERSION \
+	QT_VERSION_CHECK(ZXING_VERSION_MAJOR, ZXING_VERSION_MINOR, ZXING_VERSION_PATCH)
 #include <ZXing/ReadBarcode.h>
 
 namespace Kodaskanna
@@ -63,8 +66,13 @@ void ScanImageRunner::run()
 
     resultData->isSuccess = result.isValid();
     if (resultData->isSuccess) {
-        resultData->text = QString::fromStdWString(result.text());
+#if ZXING_VERSION < QT_VERSION_CHECK(2, 0, 0)
+        resultData->text = QString::fromStdWString(result.text());
         resultData->bytes = QByteArray(reinterpret_cast<const char *>(result.rawBytes().data()), result.rawBytes().size());
+#else
+        resultData->text = QString::fromStdString(result.text());
+        resultData->bytes = QByteArray(reinterpret_cast<const char *>(result.bytes().data()), result.bytes().size());
+#endif
     }
 
     Q_EMIT scanFinished(scanResult);
