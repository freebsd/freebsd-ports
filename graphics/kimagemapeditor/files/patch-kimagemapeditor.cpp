--- src/kimagemapeditor.cpp.orig	Sat Aug 14 01:43:23 2004
+++ src/kimagemapeditor.cpp	Sat Aug 14 01:48:29 2004
@@ -76,7 +76,7 @@
 
 // Factory code for KDE 3
 typedef KParts::GenericFactory<KImageMapEditor> KimeFactory;
-K_EXPORT_COMPONENT_FACTORY( libkimagemapeditor , KimeFactory );
+K_EXPORT_COMPONENT_FACTORY( libkimagemapeditor , KimeFactory )
 
 KImageMapEditor::KImageMapEditor(QWidget *parentWidget, const char *,
             QObject *parent, const char *name, const QStringList & )
