--- texttranslator/translator/widgets/translatordebugdialog.cpp.orig	2023-01-15 16:31:40 UTC
+++ texttranslator/translator/widgets/translatordebugdialog.cpp
@@ -19,6 +19,7 @@
 #include <QTextStream>
 #include <QVBoxLayout>
 #include <QWindow>
+#include <errno.h>
 namespace
 {
 const char myTranslatorDebugDialogConfigGroupName[] = "TranslatorDebugDialog";
