--- src/tiled/main.cpp.orig	2021-04-23 13:13:21 UTC
+++ src/tiled/main.cpp
@@ -66,10 +66,6 @@ static QTextStream& stdOut()
     return ts;
 }
 
-#if QT_VERSION >= QT_VERSION_CHECK(5,14,0)
-using Qt::endl;
-#endif
-
 namespace {
 
 class CommandLineHandler : public CommandLineParser
@@ -260,7 +256,7 @@ void CommandLineHandler::showVersion()
     if (!showedVersion) {
         showedVersion = true;
         stdOut() << QApplication::applicationDisplayName() << " "
-                 << QApplication::applicationVersion() << endl;
+                 << QApplication::applicationVersion() << Qt::endl;
         quit = true;
     }
 }
@@ -317,9 +313,9 @@ void CommandLineHandler::showExportFormats()
     }
     formats.sort(Qt::CaseSensitive);
 
-    stdOut() << tr("Map export formats:") << endl;
+    stdOut() << tr("Map export formats:") << Qt::endl;
     for (const QString &name : formats)
-        stdOut() << " " << name << endl;
+        stdOut() << " " << name << Qt::endl;
 
     formats.clear();
     const auto tilesetFormats = PluginManager::objects<TilesetFormat>();
@@ -329,9 +325,9 @@ void CommandLineHandler::showExportFormats()
     }
     formats.sort(Qt::CaseSensitive);
 
-    stdOut() << tr("Tileset export formats:") << endl;
+    stdOut() << tr("Tileset export formats:") << Qt::endl;
     for (const QString &name : formats)
-        stdOut() << " " << name << endl;
+        stdOut() << " " << name << Qt::endl;
 
     quit = true;
 }
