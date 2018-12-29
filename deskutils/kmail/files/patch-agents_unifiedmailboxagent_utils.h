--- agents/unifiedmailboxagent/utils.h.orig	2018-12-29 21:15:58 UTC
+++ agents/unifiedmailboxagent/utils.h
@@ -24,7 +24,7 @@
 #include <QHash>
 #include <QString>
 
-#include <experimental/optional>
+#include "boost_optional.h"
 namespace stdx {
 // Injects content of std::experimental namespace into "exp" namespace.
 // C++ is magical.
