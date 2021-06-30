--- src/mimonscreenplugins.cpp.orig	2021-06-28 06:11:15 UTC
+++ src/mimonscreenplugins.cpp
@@ -20,9 +20,9 @@
 #include <QDebug>
 
 #include <algorithm>
-#include <tr1/functional>
+#include <functional>
 
-using namespace std::tr1::placeholders;
+using namespace std::placeholders;
 
 namespace
 {
@@ -117,10 +117,10 @@ bool MImOnScreenPlugins::isEnabled(const QString &plug
 
     std::remove_copy_if(mEnabledSubViews.begin(), mEnabledSubViews.end(),
                         std::back_inserter(mEnabledAndAvailableSubViews),
-                        std::tr1::bind(&MImOnScreenPlugins::isSubViewUnavailable, this, _1));
+                        std::bind(&MImOnScreenPlugins::isSubViewUnavailable, this, _1));
 
     return std::find_if(mEnabledAndAvailableSubViews.begin(), mEnabledAndAvailableSubViews.end(),
-                        std::tr1::bind(equalPlugin, _1, plugin)) != mEnabledAndAvailableSubViews.end();
+                        std::bind(equalPlugin, _1, plugin)) != mEnabledAndAvailableSubViews.end();
 }
 
 bool MImOnScreenPlugins::isSubViewEnabled(const SubView &subView) const
@@ -137,7 +137,7 @@ QList<MImOnScreenPlugins::SubView> MImOnScreenPlugins:
 {
     QList<MImOnScreenPlugins::SubView> result;
     std::remove_copy_if(mEnabledSubViews.begin(), mEnabledSubViews.end(),
-                        std::back_inserter(result), std::tr1::bind(notEqualPlugin, _1, plugin));
+                        std::back_inserter(result), std::bind(notEqualPlugin, _1, plugin));
     return result;
 }
 
