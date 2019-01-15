--- src/app/main.cpp.orig	2018-11-23 12:08:36 UTC
+++ src/app/main.cpp
@@ -1025,7 +1025,7 @@ int main( int argc, char *argv[] )
   QCoreApplication::addLibraryPath( QApplication::applicationDirPath()
                                     + QDir::separator() + "qtplugins" );
 #endif
-#ifdef Q_OS_MAC
+#if defined(Q_OS_MAC) || defined(Q_OS_UNIX)
   // Resulting libraryPaths has critical QGIS plugin paths first, then any Qt plugin paths, then
   // any dev-defined paths (in app's qt.conf) and/or user-defined paths (QT_PLUGIN_PATH env var).
   //
@@ -1033,7 +1033,7 @@ int main( int argc, char *argv[] )
   //       built against a different Qt/QGIS, while still allowing custom C++ plugins to load.
   QStringList libPaths( QCoreApplication::libraryPaths() );
 
-  QgsDebugMsgLevel( QStringLiteral( "Initial macOS QCoreApplication::libraryPaths: %1" )
+  QgsDebugMsgLevel( QStringLiteral( "Initial macOS or UNIX QCoreApplication::libraryPaths: %1" )
                     .arg( libPaths.join( " " ) ), 4 );
 
   // Strip all critical paths that should always be prepended
