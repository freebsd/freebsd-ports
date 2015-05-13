Look for icons in more than just /usr/share -- upstream svn patch:
Log message

- When checking for icon themes, also check in $PREFIX
- Also ensure path is in QIcon's theme path

https://code.google.com/p/cantata/source/detail?r=5740


Index: gui/application_qt.cpp
===================================================================
--- gui/application_qt.cpp	(revision 5739)
+++ gui/application_qt.cpp	(working copy)
@@ -45,11 +45,21 @@
     // or gnome icon themes are installed, and set theme to one of those.
     if (!QIcon::hasThemeIcon("document-save-as")) {
         QStringList themes=QStringList() << QLatin1String("oxygen") << QLatin1String("gnome");
+        QStringList prefixes=QStringList() << QLatin1String("/usr") << QLatin1String("/usr/local");
+        if (!prefixes.contains(QLatin1String(INSTALL_PREFIX))) {
+            prefixes+=QLatin1String(INSTALL_PREFIX);
+        }
         foreach (const QString &theme, themes) {
-            QString dir(QLatin1String("/usr/share/icons/")+theme);
-            if (QDir(dir).exists()) {
-                QIcon::setThemeName(theme);
-                return;
+            foreach (const QString &prefix, prefixes) {
+                QString dir(prefix+QLatin1String("/share/icons/")+theme);
+                if (QDir(dir).exists()) {
+                    QIcon::setThemeName(theme);
+                    // Add to theme search paths, if it is not there already...
+                    if (!QIcon::themeSearchPaths().contains(prefix+QLatin1String("/share/icons"))) {
+                        QIcon::setThemeSearchPaths(QIcon::themeSearchPaths() << QString(prefix+QLatin1String("/share/icons")));
+                    }
+                    return;
+                }
             }
         }
     }
