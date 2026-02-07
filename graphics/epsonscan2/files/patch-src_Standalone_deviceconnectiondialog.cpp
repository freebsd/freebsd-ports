--- src/Standalone/deviceconnectiondialog.cpp.orig	2024-09-12 07:10:42 UTC
+++ src/Standalone/deviceconnectiondialog.cpp
@@ -111,7 +111,7 @@ void DetectAlertGlassDirty(SDIScannerDriver* driver, S
         dir_name = dir_name + "A_UI_006";
         if(!tmpdir.exists(dir_name.c_str())){
             if(!tmpdir.exists(dir_name.c_str())) tmpdir.mkdir(dir_name.c_str());
-            if(!QProcess::startDetached(executable)){
+            if(!QProcess::startDetached(exeapp, {arg1, arg2, arg3, "A_UI_006", std::to_string( 1).c_str()})){
                 qCritical() << "Cannot start program";
             }
         }
@@ -130,7 +130,7 @@ void DetectAlertGlassDirty(SDIScannerDriver* driver, S
         dir_name = dir_name + "A_UNIT_008";
         if(!tmpdir.exists(dir_name.c_str())){
             if(!tmpdir.exists(dir_name.c_str())) tmpdir.mkdir(dir_name.c_str());
-            if(!QProcess::startDetached(executable)){
+            if(!QProcess::startDetached(exeapp, {arg1, arg2, arg3, "A_UNIT_008", std::to_string( 2).c_str()})){
                 qCritical() << "Cannot start program";
             }
         }
