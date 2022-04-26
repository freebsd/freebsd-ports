--- src/Standalone/deviceconnectiondialog.cpp.orig	2022-02-17 18:43:44 UTC
+++ src/Standalone/deviceconnectiondialog.cpp
@@ -110,11 +110,10 @@ void DetectAlertGlassDirty(SDIScannerDriver* driver, S
 #endif
         QString arg2(TranslationString::GetString().translation_str.A_UI_006);
         QString arg3(TranslationString::GetString().translation_str.VERSION_003);
-        QString executable = exeapp + " " + arg1 + " " + "\"" + arg2 + "\"" + " " + arg3 + " " + "A_UI_006" + " " + std::to_string( 1).c_str();
         dir_name = dir_name + "A_UI_006";
         if(!tmpdir.exists(dir_name.c_str())){
             if(!tmpdir.exists(dir_name.c_str())) tmpdir.mkdir(dir_name.c_str());
-            if(!QProcess::startDetached(executable)){
+	    if(!QProcess::startDetached(exeapp, {arg1, arg2, arg3, "A_UI_006", std::to_string( 1).c_str()})){
                 qCritical() << "Cannot start program";
             }
         }
@@ -129,11 +128,10 @@ void DetectAlertGlassDirty(SDIScannerDriver* driver, S
 #endif
         QString arg2(TranslationString::GetString().translation_str.A_UNIT_008);
         QString arg3(TranslationString::GetString().translation_str.VERSION_003);
-        QString executable = exeapp + " " + arg1 + " " + "\"" + arg2 + "\"" + " " + arg3 + " " + "A_UNIT_008" + " " + std::to_string( 2).c_str();
         dir_name = dir_name + "A_UNIT_008";
         if(!tmpdir.exists(dir_name.c_str())){
             if(!tmpdir.exists(dir_name.c_str())) tmpdir.mkdir(dir_name.c_str());
-            if(!QProcess::startDetached(executable)){
+            if(!QProcess::startDetached(exeapp, {arg1, arg2, arg3, "A_UNIT_008", std::to_string( 2).c_str()})){
                 qCritical() << "Cannot start program";
             }
         }
