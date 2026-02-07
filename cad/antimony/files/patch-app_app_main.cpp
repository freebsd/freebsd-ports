--- app/app/main.cpp.orig	2023-01-16 19:52:05 UTC
+++ app/app/main.cpp
@@ -69,6 +69,17 @@ int main(int argc, char *argv[])
             fab_paths.push_back(p.toStdString());
         }
         fab::postInit(fab_paths);	
+#elif defined Q_OS_FREEBSD
+        auto dir = QCoreApplication::applicationDirPath();
+        std::vector<std::string> fab_paths =
+            {(dir + "/sb").toStdString(),
+             (dir + "/../share/antimony/").toStdString()};
+        for (auto p : QStandardPaths::standardLocations(
+                QStandardPaths::AppDataLocation))
+        {
+            fab_paths.push_back(p.toStdString());
+        }
+        fab::postInit(fab_paths);	
 #elif defined Q_OS_WIN32
         auto dir = QCoreApplication::applicationDirPath();
         fab::postInit({(dir + "/sb").toStdString()});
