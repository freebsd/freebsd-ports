--- ./commentseditor/plugin_commentseditor.cpp.orig	Sat Sep  4 11:36:04 2004
+++ ./commentseditor/plugin_commentseditor.cpp	Sat Sep  4 11:36:12 2004
@@ -34,7 +34,7 @@
 #include "commentseditor.h"
 
 K_EXPORT_COMPONENT_FACTORY( digikamplugin_commentseditor,
-                            KGenericFactory<Plugin_CommentsEditor>("digikam"));
+                            KGenericFactory<Plugin_CommentsEditor>("digikam"))
 
 Plugin_CommentsEditor::Plugin_CommentsEditor(QObject *parent,
                                              const char*,
