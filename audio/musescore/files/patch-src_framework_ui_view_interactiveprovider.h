--- src/framework/ui/view/interactiveprovider.h.orig	2023-07-14 10:15:25 UTC
+++ src/framework/ui/view/interactiveprovider.h
@@ -26,6 +26,7 @@
 #include <QVariant>
 #include <QMap>
 #include <QStack>
+#include <QEventLoop>
 
 #include "modularity/ioc.h"
 #include "../iinteractiveprovider.h"
